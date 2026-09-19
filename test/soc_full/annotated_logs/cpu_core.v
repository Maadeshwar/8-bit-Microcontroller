//      // verilator_coverage annotation
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
 225031     always @(*) begin
 225031         data_rdata = 8'h00;
 224536         if (operand <= 8'h07) begin
 000495             data_rdata = ram[operand[2:0]];
 224536         end else begin
 224536             case (operand)
 000018                 8'h20: data_rdata = {3'b000, uio_in[4:0]}; // GPIO IN
%000009                 8'h21: data_rdata = {3'b000, gpio_dir};    // GPIO DIR
%000009                 8'h22: data_rdata = timer;                 // TIMER
%000009                 8'h23: data_rdata = rx_data;               // UART RX DATA
 000243                 8'h25: data_rdata = {6'b0, tx_busy, rx_ready}; // UART STATUS
 000018                 8'h26: data_rdata = pwm_duty;              // PWM DUTY
%000009                 8'h28: data_rdata = baud_div[7:0];         // BAUD_DIV_L
%000009                 8'h29: data_rdata = baud_div[15:8];        // BAUD_DIV_H
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
        
 075010     always @(posedge clk or negedge rst_n) begin
        
 000010         if (!rst_n) begin
 000010             state <= FETCH;
~075000         end else if (ena) begin
 075000             state <= next_state;
                end
            end
        
            // Process 2: Next State Logic (Combinational)
 225031     always @(*) begin
 225031         next_state = state; // Default to hold state
 225031         case (state)
 075031             FETCH: begin
 075000                 if (instr_in == 8'h00)
 000031                     next_state = FETCH;
                        else
 075000                     next_state = FETCH_OP;
                    end
 075000             FETCH_OP: begin
 075000                 next_state = EXEC;
                    end
 075000             EXEC: begin
 075000                 next_state = FETCH;
                    end
%000000             default: next_state = FETCH;
                endcase
            end
        
            // Process 3: Output / Datapath Logic (Synchronous)
 075010     always @(posedge clk or negedge rst_n) begin
 000010         if (!rst_n) begin
 000010             pc_out      <= 8'h00;
 000010             acc         <= 8'h00;
 000010             ir          <= 8'h00;
 000010             operand     <= 8'h00;
 000010             ret_addr    <= 8'h00;
 000010             flag_z      <= 1'b0;
 000010             flag_c      <= 1'b0;
 000010             timer       <= 8'h00;
 000010             baud_div    <= 16'd434;
 000010             gpio_out    <= 5'h00;
 000010             gpio_dir    <= 5'h00;
 000010             pwm_duty    <= 8'h00;
 000010             pwm_counter <= 8'h00;
 000010             tx_start    <= 1'b0;
 000010             rx_clear    <= 1'b0;
 000080             for (i = 0; i < 8; i = i + 1) ram[i] <= 8'h00;
 000010             acc         <= 8'h00;
 000010             ir          <= 8'h00;
 000010             operand     <= 8'h00;
 000010             ret_addr    <= 8'h00;
 000010             flag_z      <= 1'b0;
 000010             flag_c      <= 1'b0;
 000010             timer       <= 8'h00;
 000010             baud_div    <= 16'd434;
 000010             gpio_out    <= 5'h00;
 000010             gpio_dir    <= 5'h00;
 000010             pwm_duty    <= 8'h00;
 000010             pwm_counter <= 8'h00;
 000010             tx_start    <= 1'b0;
 000010             rx_clear    <= 1'b0;
~075000         end else if (ena) begin
 075000             timer       <= timer + 1; // Timer always ticking
 075000             pwm_counter <= pwm_counter + 1; // PWM counter always ticking
                    
 075000             tx_start    <= 1'b0;      // Default pulse signals low every cycle
 075000             rx_clear    <= 1'b0;
                    
 075000             case (state)
 025000                 FETCH: begin
 025000                     ir     <= instr_in;
 025000                     pc_out <= pc_out + 1;
                        end
                        
 025000                 FETCH_OP: begin
 025000                     operand <= instr_in;
 025000                     pc_out  <= pc_out + 1;
                        end
                        
 025000                 EXEC: begin
 025000                     case (ir)
 000015                         8'h01: begin // LDI
 000015                             acc    <= operand;
 000015                             flag_z <= (operand == 8'h00);
 000015                             flag_c <= 1'b0;
                                end
        
 000029                         8'h02: begin // LDR
 000029                             acc    <= data_rdata;
 000029                             flag_z <= (data_rdata == 8'h00);
 000029                             flag_c <= 1'b0;
~000028                             if (operand == 8'h23) rx_clear <= 1'b1;
                                end
        
 000014                         8'h03: begin // STR
%000007                             if (operand <= 8'h07) begin
%000007                                 ram[operand[2:0]] <= acc;
%000007                             end else begin
%000007                                 case (operand)
%000001                                     8'h20: gpio_out <= acc[4:0];
%000001                                     8'h21: gpio_dir <= acc[4:0];
%000001                                     8'h22: timer    <= 8'h00;
%000001                                     8'h24: begin                 // UART TX
%000001                                         tx_start <= 1'b1;
                                            end
%000001                                     8'h26: pwm_duty <= acc;
%000001                                     8'h28: baud_div[7:0] <= acc;
%000001                                     8'h29: baud_div[15:8] <= acc;
%000000                                     default: ;
                                        endcase
                                    end
                                end
        
%000001                         8'h04: begin // ADD
%000001                             {flag_c, acc} <= alu_add;
%000001                             flag_z        <= (alu_add[7:0] == 8'h00);
                                end
%000001                         8'h05: begin // SUB
%000001                             {flag_c, acc} <= alu_sub;
%000001                             flag_z        <= (alu_sub[7:0] == 8'h00);
                                end
 024872                         8'h06: pc_out <= operand;            // JMP
~000022                         8'h07: if (flag_z)  pc_out <= operand; // JZ
        
 000028                         8'h08: begin // AND
 000028                             acc    <= alu_and;
 000028                             flag_z <= (alu_and == 8'h00);
 000028                             flag_c <= 1'b0;
                                end
%000001                         8'h09: begin // OR
%000001                             acc    <= alu_or;
%000001                             flag_z <= (alu_or == 8'h00);
%000001                             flag_c <= 1'b0;
                                end
%000001                         8'h0A: begin // XOR
%000001                             acc    <= alu_xor;
%000001                             flag_z <= (alu_xor == 8'h00);
%000001                             flag_c <= 1'b0;
                                end
        
%000001                         8'h0B: begin // SHL
%000001                             acc    <= alu_shl;
%000001                             flag_z <= (alu_shl == 8'h00);
%000001                             flag_c <= 1'b0;
                                end
%000001                         8'h0C: begin // SHR
%000001                             acc    <= alu_shr;
%000001                             flag_z <= (alu_shr == 8'h00);
%000001                             flag_c <= 1'b0;
                                end
        
%000001                         8'h0D: begin // CALL
%000001                             ret_addr <= pc_out;
%000001                             pc_out   <= operand;
                                end
%000001                         8'h0E: pc_out <= ret_addr;           // RET
        
%000009                         8'h0F: if (!flag_z) pc_out <= operand; // JNZ
%000001                         8'h10: if (flag_c)  pc_out <= operand; // JC
        
%000002                         default: ; // Unknown opcode = NOP
                            endcase
                        end
                        
%000000                 default: ; // State 3 does nothing
                    endcase
                end
            end
        
        endmodule
        
