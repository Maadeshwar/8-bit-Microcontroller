`default_nettype none

module tb_formal (
    input wire clk,
    input wire rst_n,
    input wire ena,
    input wire [7:0] ui_in,
    input wire [7:0] uio_in
);

    wire [7:0] uo_out;
    wire [7:0] uio_out;
    wire [7:0] uio_oe;

    tt_um_tinysoc dut (
        .ui_in(ui_in),
        .uo_out(uo_out),
        .uio_in(uio_in),
        .uio_out(uio_out),
        .uio_oe(uio_oe),
        .ena(ena),
        .clk(clk),
        .rst_n(rst_n)
    );

`ifdef FORMAL
    // Assume reset is asserted initially
    reg past_valid;
    initial past_valid = 0;
    always @(posedge clk) past_valid <= 1;

    always @(posedge clk) begin
        if (!past_valid) begin
            assume(!rst_n);
        end
    end

    // Assert that FSM state is always valid (0, 1, or 2)
    always @(posedge clk) begin
        if (rst_n) begin
            assert(dut.core.state == 0 || dut.core.state == 1 || dut.core.state == 2);
        end
    end

    // Assert that PC never exceeds 255 (it's 8 bits, so this is trivially true, but good for sanity)
    always @(posedge clk) begin
        if (rst_n) begin
            assert(dut.core.pc_out <= 8'hFF);
        end
    end

    // Pin enables are fixed by the SoC pin contract: GPIO is programmable,
    // UART TX and PWM are outputs, and UART RX is an input.
    always @(posedge clk) begin
        if (rst_n) begin
            assert(dut.uio_oe[7] == 1'b1);
            assert(dut.uio_oe[6] == 1'b0);
            assert(dut.uio_oe[5] == 1'b1);
        end
    end

    // The UART must remain idle-high whenever its transmitter is idle.
    always @(posedge clk) begin
        if (rst_n && !dut.core.tx_inst.tx_busy) begin
            assert(dut.core.tx_inst.tx == 1'b1);
        end
    end
`endif

endmodule
