`default_nettype none

module cpu_core (
    input  wire       clk,
    input  wire       rst_n,
    input  wire       ena,
    input  wire [7:0] instr_in,
    output reg  [7:0] pc_out,
    input  wire [7:0] uio_in,
    output wire [7:0] uio_out,
    output wire [7:0] uio_oe
);

    // 16-byte Internal RAM
    reg [7:0] ram [0:7];
    
    // CPU Registers
    reg [7:0] acc;
    reg [7:0] ir;       // Instruction Register (latches opcode)
    reg [7:0] operand;  // Operand Register (latches second byte)
    reg [1:0] state;
    
    // Peripherals
    reg [7:0] timer;
    reg [4:0] gpio_out;
    reg [4:0] gpio_dir;
    
    // PWM
    reg [7:0] pwm_duty;
    reg [7:0] pwm_counter;
    wire pwm_out = (pwm_counter < pwm_duty);
    
    // Watchdog Timer (WDT)
    reg [15:0] wdt_count;
    reg        wdt_enable;
    wire       wdt_reset_req = (wdt_count == 16'hFFFF);
    
    // UART signals
    wire tx_busy;
    reg  tx_start;
    reg  [7:0] tx_data;
    
    wire rx_ready;
    wire [7:0] rx_data;
    reg  rx_clear;

    // Physical pin assignments
    // uio[7] = PWM OUT
    // uio[6] = UART RX (always input)
    // uio[5] = UART TX (always output)
    // uio[4:0] = GPIO (direction controlled per-bit via gpio_dir)
    wire uart_tx_pin;
    assign uio_out = {pwm_out, 1'b0, uart_tx_pin, gpio_out};
    assign uio_oe  = {1'b1, 1'b0, 1'b1, gpio_dir};

    // Sink unused uio_in to prevent Verilator warning
    wire _unused = &{1'b0, uio_in[7], uio_in[5], 1'b0};
    
    // Instantiate UART (50MHz clock, 115200 baud => 434 clocks per bit)
    uart_tx #(.CLKS_PER_BIT(434)) tx_inst (
        .clk(clk),
        .rst_n(rst_n),
        .tx_start(tx_start),
        .tx_data(tx_data),
        .tx(uart_tx_pin),
        .tx_busy(tx_busy)
    );

    uart_rx #(.CLKS_PER_BIT(434)) rx_inst (
        .clk(clk),
        .rst_n(rst_n),
        .rx(uio_in[6]),
        .rx_data(rx_data),
        .rx_ready(rx_ready),
        .rx_clear(rx_clear)
    );

    // -----------------------------------------------------------
    // Data Read Bus (combinational, uses LATCHED operand register)
    // -----------------------------------------------------------
    reg [7:0] data_rdata;
    always @(*) begin
        if (operand <= 8'h07) begin
            data_rdata = ram[operand[2:0]];
        end else begin
            case (operand)
                8'h20: data_rdata = {3'b000, uio_in[4:0]}; // GPIO IN
                8'h21: data_rdata = {3'b000, gpio_dir};    // GPIO DIR
                8'h22: data_rdata = timer;                 // TIMER
                8'h23: data_rdata = rx_data;               // UART RX DATA
                8'h25: data_rdata = {6'b0, tx_busy, rx_ready}; // UART STATUS
                8'h26: data_rdata = pwm_duty;              // PWM DUTY
                8'h27: data_rdata = wdt_count[15:8];       // WDT Upper Count
                default: data_rdata = 8'h00;
            endcase
        end
    end

    // FSM States
    localparam FETCH    = 2'd0;
    localparam FETCH_OP = 2'd1;
    localparam EXEC     = 2'd2;

    reg [1:0] next_state;
    integer i;

    // Process 1: State Memory (Synchronous)
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= FETCH;
        end else if (wdt_reset_req) begin
            state <= FETCH;
        end else if (ena) begin
            state <= next_state;
        end
    end

    // Process 2: Next State Logic (Combinational)
    always @(*) begin
        next_state = state; // Default to hold state
        case (state)
            FETCH: begin
                if (instr_in == 8'h00)
                    next_state = FETCH;
                else
                    next_state = FETCH_OP;
            end
            FETCH_OP: begin
                next_state = EXEC;
            end
            EXEC: begin
                next_state = FETCH;
            end
            default: next_state = FETCH;
        endcase
    end

    // Process 3: Output / Datapath Logic (Synchronous)
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc_out      <= 8'h00;
            acc         <= 8'h00;
            ir          <= 8'h00;
            operand     <= 8'h00;
            timer       <= 8'h00;
            gpio_out    <= 5'h00;
            gpio_dir    <= 5'h00;
            pwm_duty    <= 8'h00;
            pwm_counter <= 8'h00;
            tx_start    <= 1'b0;
            tx_data     <= 8'h00;
            rx_clear    <= 1'b0;
            wdt_count   <= 16'h0000;
            wdt_enable  <= 1'b0;
            for (i = 0; i < 8; i = i + 1) ram[i] <= 8'h00;
        end else if (wdt_reset_req) begin
            pc_out      <= 8'h00;
            acc         <= 8'h00;
            ir          <= 8'h00;
            operand     <= 8'h00;
            timer       <= 8'h00;
            gpio_out    <= 5'h00;
            gpio_dir    <= 5'h00;
            pwm_duty    <= 8'h00;
            pwm_counter <= 8'h00;
            tx_start    <= 1'b0;
            tx_data     <= 8'h00;
            rx_clear    <= 1'b0;
            wdt_count   <= 16'h0000;
            wdt_enable  <= 1'b0;
        end else if (ena) begin
            timer       <= timer + 1; // Timer always ticking
            pwm_counter <= pwm_counter + 1; // PWM counter always ticking
            if (wdt_enable) wdt_count <= wdt_count + 1; // WDT ticks
            
            tx_start    <= 1'b0;      // Default pulse signals low every cycle
            rx_clear    <= 1'b0;
            
            case (state)
                FETCH: begin
                    ir     <= instr_in;
                    pc_out <= pc_out + 1;
                end
                
                FETCH_OP: begin
                    operand <= instr_in;
                    pc_out  <= pc_out + 1;
                end
                
                EXEC: begin
                    case (ir)
                        8'h01: acc <= operand; // LDI

                        8'h02: begin // LDR
                            acc <= data_rdata;
                            if (operand == 8'h23) rx_clear <= 1'b1;
                        end

                        8'h03: begin // STR
                            if (operand <= 8'h07) begin
                                ram[operand[2:0]] <= acc;
                            end else begin
                                case (operand)
                                    8'h20: gpio_out <= acc[4:0];
                                    8'h21: gpio_dir <= acc[4:0];
                                    8'h22: timer    <= 8'h00;   // Reset timer
                                    8'h24: begin                 // UART TX
                                        tx_data  <= acc;
                                        tx_start <= 1'b1;
                                    end
                                    8'h26: pwm_duty <= acc;     // PWM DUTY
                                    8'h27: begin                // WDT KICK
                                        wdt_count  <= 16'h0000;
                                        wdt_enable <= 1'b1;
                                    end
                                    default: ; 
                                endcase
                            end
                        end

                        8'h04: acc <= acc + data_rdata; // ADD
                        8'h05: acc <= acc - data_rdata; // SUB
                        8'h06: pc_out <= operand;       // JMP
                        8'h07: if (acc == 8'h00) pc_out <= operand; // JZ
                        
                        8'h08: acc <= acc & data_rdata; // AND
                        8'h09: acc <= acc | data_rdata; // OR
                        8'h0A: acc <= acc ^ data_rdata; // XOR
                        
                        8'h0B: acc <= acc << data_rdata[2:0]; // SHL
                        8'h0C: acc <= acc >> data_rdata[2:0]; // SHR

                        default: ; // Unknown opcode = NOP
                    endcase
                end
                
                default: ; // State 3 does nothing
            endcase
        end
    end

endmodule
