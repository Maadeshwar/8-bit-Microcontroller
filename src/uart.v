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

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state       <= IDLE;
            tx          <= 1'b1;  // UART idle line is HIGH
            clk_count   <= 16'd0;
            bit_index   <= 3'd0;
            tx_data_reg <= 8'd0;
        end else begin
            case (state)
                IDLE: begin
                    tx        <= 1'b1;
                    
                    
                    if (tx_start) begin
                        tx_data_reg <= tx_data;
                        state       <= START;
                    end
                end

                START: begin
                    tx <= 1'b0; // Start bit is LOW
                    if (clk_count != clks_per_bit) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        clk_count <= 16'd0;
                        state     <= DATA;
                    end
                end

                DATA: begin
                    tx <= tx_data_reg[0]; // LSB first via shift register
                    if (clk_count != clks_per_bit) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        clk_count   <= 16'd0;
                        tx_data_reg <= {1'b0, tx_data_reg[7:1]}; // shift out LSB
                        if (bit_index < 3'd7) begin
                            bit_index <= bit_index + 1;
                        end else begin
                            bit_index <= 3'd0;
                            state     <= STOPBIT;
                        end
                    end
                end

                STOPBIT: begin
                    tx <= 1'b1; // Stop bit is HIGH
                    if (clk_count != clks_per_bit) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        clk_count <= 16'd0;
                        state     <= IDLE;
                    end
                end

                default: state <= IDLE;
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
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rx_r1 <= 1'b1; // UART idle is HIGH
            rx_r2 <= 1'b1;
        end else begin
            rx_r1 <= rx;
            rx_r2 <= rx_r1;
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state     <= IDLE;
            clk_count <= 16'd0;
            bit_index <= 3'd0;
            rx_data   <= 8'd0;
            rx_ready  <= 1'b0;
        end else begin
            // Default: clear ready flag on request
            if (rx_clear) rx_ready <= 1'b0;

            case (state)
                IDLE: begin
                    
                    
                    // Falling edge = start bit detected
                    if (rx_r2 == 1'b0) begin
                        state <= START;
                    end
                end

                // Wait half a bit period then sample at the center of the start bit
                START: begin
                    if (clk_count == (clks_per_bit >> 1)) begin
                        clk_count <= 16'd0;
                        // Confirm it is still low (not a glitch)
                        if (rx_r2 == 1'b0) begin
                            state <= DATA;
                        end else begin
                            state <= IDLE; // False start, go back
                        end
                    end else begin
                        clk_count <= clk_count + 1;
                    end
                end

                // Sample each bit at the center of the bit period
                DATA: begin
                    if (clk_count != clks_per_bit) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        clk_count          <= 16'd0;
                        rx_data <= {rx_r2, rx_data[7:1]}; // Sample at center
                        if (bit_index < 3'd7) begin
                            bit_index <= bit_index + 1;
                        end else begin
                            bit_index <= 3'd0;
                            state     <= STOPBIT;
                        end
                    end
                end

                STOPBIT: begin
                    if (clk_count != clks_per_bit) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        // Only assert rx_ready if stop bit is valid HIGH
                        if (rx_r2 == 1'b1) rx_ready <= 1'b1;
                        clk_count <= 16'd0;
                        state     <= IDLE;
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end
endmodule

