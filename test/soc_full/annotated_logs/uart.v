//      // verilator_coverage annotation
        `default_nettype none
        
        /* verilator lint_off DECLFILENAME */
        
        // =============================================================
        // uart_tx: 8N1 Serial Transmitter
        // =============================================================
        module uart_tx (
            input  wire        clk,
            input  wire        rst_n,
            input  wire [15:0] clks_per_bit,
            input  wire        tx_start,  // Single-cycle pulse to start TX
            input  wire [7:0]  tx_data,
            output reg         tx,
            output wire        tx_busy
        );
            localparam IDLE     = 2'd0;
            localparam START    = 2'd1;
            localparam DATA     = 2'd2;
            localparam STOPBIT  = 2'd3;
        
            reg [1:0]  state;
            reg [15:0] clk_count;
            reg [2:0]  bit_index;
            reg [7:0]  tx_data_reg;
        
            assign tx_busy = (state != IDLE);
        
 075010     always @(posedge clk or negedge rst_n) begin
 075000         if (!rst_n) begin
 000010             state       <= IDLE;
 000010             tx          <= 1'b1;  // UART idle line is HIGH
 000010             clk_count   <= 16'd0;
 000010             bit_index   <= 3'd0;
 000010             tx_data_reg <= 8'd0;
 075000         end else begin
 075000             case (state)
 074940                 IDLE: begin
 074940                     tx        <= 1'b1;
                            
                            
~074939                     if (tx_start) begin
%000001                         tx_data_reg <= tx_data;
%000001                         state       <= START;
                            end
                        end
        
%000006                 START: begin
%000006                     tx <= 1'b0; // Start bit is LOW
%000005                     if (clk_count != clks_per_bit) begin
%000005                         clk_count <= clk_count + 1;
%000001                     end else begin
%000001                         clk_count <= 16'd0;
%000001                         state     <= DATA;
                            end
                        end
        
 000048                 DATA: begin
 000048                     tx <= tx_data_reg[0]; // LSB first via shift register
~000040                     if (clk_count != clks_per_bit) begin
 000040                         clk_count <= clk_count + 1;
%000008                     end else begin
%000008                         clk_count   <= 16'd0;
%000008                         tx_data_reg <= {1'b0, tx_data_reg[7:1]}; // shift out LSB
%000007                         if (bit_index < 3'd7) begin
%000007                             bit_index <= bit_index + 1;
%000001                         end else begin
%000001                             bit_index <= 3'd0;
%000001                             state     <= STOPBIT;
                                end
                            end
                        end
        
%000006                 STOPBIT: begin
%000006                     tx <= 1'b1; // Stop bit is HIGH
%000005                     if (clk_count != clks_per_bit) begin
%000005                         clk_count <= clk_count + 1;
%000001                     end else begin
%000001                         clk_count <= 16'd0;
%000001                         state     <= IDLE;
                            end
                        end
        
%000000                 default: state <= IDLE;
                    endcase
                end
            end
        endmodule
        
        
        // =============================================================
        // uart_rx: 8N1 Serial Receiver with oversampling (center tap)
        // =============================================================
        module uart_rx (
            input  wire        clk,
            input  wire        rst_n,
            input  wire [15:0] clks_per_bit,
            input  wire        rx,
            output reg [7:0]   rx_data,
            output reg         rx_ready,   // Pulses high for 1 cycle when byte ready
            input  wire        rx_clear    // Clears rx_ready flag
        );
            localparam IDLE    = 2'd0;
            localparam START   = 2'd1;
            localparam DATA    = 2'd2;
            localparam STOPBIT = 2'd3;
        
            reg [1:0]  state;
            reg [15:0] clk_count;
            reg [2:0]  bit_index;
        
            // Double-register RX input to prevent metastability
            reg rx_r1, rx_r2;
 075010     always @(posedge clk or negedge rst_n) begin
 075000         if (!rst_n) begin
 000010             rx_r1 <= 1'b1; // UART idle is HIGH
 000010             rx_r2 <= 1'b1;
 075000         end else begin
 075000             rx_r1 <= rx;
 075000             rx_r2 <= rx_r1;
                end
            end
        
 075010     always @(posedge clk or negedge rst_n) begin
 075000         if (!rst_n) begin
 000010             state     <= IDLE;
 000010             clk_count <= 16'd0;
 000010             bit_index <= 3'd0;
 000010             rx_data   <= 8'd0;
 000010             rx_ready  <= 1'b0;
 075000         end else begin
                    // Default: clear ready flag on request
~074999             if (rx_clear) rx_ready <= 1'b0;
        
 075000             case (state)
 074943                 IDLE: begin
                            
                            
                            // Falling edge = start bit detected
~074942                     if (rx_r2 == 1'b0) begin
%000001                         state <= START;
                            end
                        end
        
                        // Wait half a bit period then sample at the center of the start bit
%000003                 START: begin
%000002                     if (clk_count == (clks_per_bit >> 1)) begin
%000001                         clk_count <= 16'd0;
                                // Confirm it is still low (not a glitch)
%000001                         if (rx_r2 == 1'b0) begin
%000001                             state <= DATA;
%000000                         end else begin
%000000                             state <= IDLE; // False start, go back
                                end
%000002                     end else begin
%000002                         clk_count <= clk_count + 1;
                            end
                        end
        
                        // Sample each bit at the center of the bit period
 000048                 DATA: begin
~000040                     if (clk_count != clks_per_bit) begin
 000040                         clk_count <= clk_count + 1;
%000008                     end else begin
%000008                         clk_count          <= 16'd0;
%000008                         rx_data <= {rx_r2, rx_data[7:1]}; // Sample at center
%000007                         if (bit_index < 3'd7) begin
%000007                             bit_index <= bit_index + 1;
%000001                         end else begin
%000001                             bit_index <= 3'd0;
%000001                             state     <= STOPBIT;
                                end
                            end
                        end
        
%000006                 STOPBIT: begin
%000005                     if (clk_count != clks_per_bit) begin
%000005                         clk_count <= clk_count + 1;
%000001                     end else begin
                                // Only assert rx_ready if stop bit is valid HIGH
%000001                         if (rx_r2 == 1'b1) rx_ready <= 1'b1;
%000001                         clk_count <= 16'd0;
%000001                         state     <= IDLE;
                            end
                        end
        
%000000                 default: state <= IDLE;
                    endcase
                end
            end
        endmodule
        
        
