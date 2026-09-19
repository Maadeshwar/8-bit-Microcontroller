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

    // 8-byte Internal RAM
    reg [7:0] ram [0:7];
    
    // CPU Registers
    reg [7:0] acc;
    reg [7:0] ir;       // Instruction Register (latches opcode)
    reg [7:0] operand;  // Operand Register (latches second byte)
    reg [7:0] ret_addr; // Return address for CALL/RET
    reg [1:0] state;
    
    // Peripherals
    reg [7:0] timer;
    reg [15:0] baud_div;
    reg [4:0] gpio_out;
    reg [4:0] gpio_dir;
    
    // PWM
    reg [7:0] pwm_duty;
    reg [7:0] pwm_counter;
    wire pwm_out = (pwm_counter < pwm_duty);
    

    // ALU Flags
    reg flag_z; // Zero flag: set when ALU result is 0x00
    reg flag_c; // Carry flag: set on ADD overflow or SUB borrow
    
    // UART signals
    wire tx_busy;
    reg  tx_start;
    
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
    uart_tx tx_inst (
        .clks_per_bit(baud_div),
        .clk(clk),
        .rst_n(rst_n),
        .tx_start(tx_start),
        .tx_data(acc),
        .tx(uart_tx_pin),
        .tx_busy(tx_busy)
    );

    uart_rx rx_inst (
        .clks_per_bit(baud_div),
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
        data_rdata = 8'h00;
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
                8'h28: data_rdata = baud_div[7:0];         // BAUD_DIV_L
                8'h29: data_rdata = baud_div[15:8];        // BAUD_DIV_H
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

    // Combinatorial ALU to save area and share adder/comparator logic
    wire [8:0] alu_add = {1'b0, acc} + {1'b0, data_rdata};
    wire [8:0] alu_sub = {1'b0, acc} - {1'b0, data_rdata};
    wire [7:0] alu_and = acc & data_rdata;
    wire [7:0] alu_or  = acc | data_rdata;
    wire [7:0] alu_xor = acc ^ data_rdata;
    wire [7:0] alu_shl = acc << data_rdata[2:0];
    wire [7:0] alu_shr = acc >> data_rdata[2:0];

    always @(posedge clk or negedge rst_n) begin

        if (!rst_n) begin
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
            ret_addr    <= 8'h00;
            flag_z      <= 1'b0;
            flag_c      <= 1'b0;
            timer       <= 8'h00;
            baud_div    <= 16'd434;
            gpio_out    <= 5'h00;
            gpio_dir    <= 5'h00;
            pwm_duty    <= 8'h00;
            pwm_counter <= 8'h00;
            tx_start    <= 1'b0;
            rx_clear    <= 1'b0;
            for (i = 0; i < 8; i = i + 1) ram[i] <= 8'h00;
        end else if (ena) begin
            timer       <= timer + 1; // Timer always ticking
            pwm_counter <= pwm_counter + 1; // PWM counter always ticking
            
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
                        8'h01: begin // LDI
                            acc    <= operand;
                            flag_z <= (operand == 8'h00);
                            flag_c <= 1'b0;
                        end

                        8'h02: begin // LDR
                            acc    <= data_rdata;
                            flag_z <= (data_rdata == 8'h00);
                            flag_c <= 1'b0;
                            if (operand == 8'h23) rx_clear <= 1'b1;
                        end

                        8'h03: begin // STR
                            if (operand <= 8'h07) begin
                                ram[operand[2:0]] <= acc;
                            end else begin
                                case (operand)
                                    8'h20: gpio_out <= acc[4:0];
                                    8'h21: gpio_dir <= acc[4:0];
                                    8'h22: timer    <= 8'h00;
                                    8'h24: begin                 // UART TX
                                        tx_start <= 1'b1;
                                    end
                                    8'h26: pwm_duty <= acc;
                                    8'h28: baud_div[7:0] <= acc;
                                    8'h29: baud_div[15:8] <= acc;
                                    default: ;
                                endcase
                            end
                        end

                        8'h04: begin // ADD
                            {flag_c, acc} <= alu_add;
                            flag_z        <= (alu_add[7:0] == 8'h00);
                        end
                        8'h05: begin // SUB
                            {flag_c, acc} <= alu_sub;
                            flag_z        <= (alu_sub[7:0] == 8'h00);
                        end
                        8'h06: pc_out <= operand;            // JMP
                        8'h07: if (flag_z)  pc_out <= operand; // JZ

                        8'h08: begin // AND
                            acc    <= alu_and;
                            flag_z <= (alu_and == 8'h00);
                            flag_c <= 1'b0;
                        end
                        8'h09: begin // OR
                            acc    <= alu_or;
                            flag_z <= (alu_or == 8'h00);
                            flag_c <= 1'b0;
                        end
                        8'h0A: begin // XOR
                            acc    <= alu_xor;
                            flag_z <= (alu_xor == 8'h00);
                            flag_c <= 1'b0;
                        end

                        8'h0B: begin // SHL
                            acc    <= alu_shl;
                            flag_z <= (alu_shl == 8'h00);
                            flag_c <= 1'b0;
                        end
                        8'h0C: begin // SHR
                            acc    <= alu_shr;
                            flag_z <= (alu_shr == 8'h00);
                            flag_c <= 1'b0;
                        end

                        8'h0D: begin // CALL
                            ret_addr <= pc_out;
                            pc_out   <= operand;
                        end
                        8'h0E: pc_out <= ret_addr;           // RET

                        8'h0F: if (!flag_z) pc_out <= operand; // JNZ
                        8'h10: if (flag_c)  pc_out <= operand; // JC

                        default: ; // Unknown opcode = NOP
                    endcase
                end
                
                default: ; // State 3 does nothing
            endcase
        end
    end

endmodule
