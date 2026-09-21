`default_nettype none

module tt_um_tinysoc_uart_tb (
    input  wire [7:0] ui_in,
    output wire [7:0] uo_out,
    input  wire [7:0] uio_in,
    output wire [7:0] uio_out,
    output wire [7:0] uio_oe,
    input  wire       ena,
    input  wire       clk,
    input  wire       rst_n,
    input  wire       corrupt_stop,
    output wire       debug_rx_ready,
    output wire [7:0] debug_rx_data
);
    wire [7:0] loopback_uio_in;
    wire [7:0] dut_uio_out;
    wire [7:0] dut_uio_oe;

    // Keep all external inputs available except RX, which is looped back from
    // TX.  corrupt_stop is used only by the framing-error test.
    assign loopback_uio_in = {
        uio_in[7],
        (corrupt_stop && dut.core.tx_inst.state == 2'd3) ? 1'b0 : dut_uio_out[5],
        uio_in[5:0]
    };

    tt_um_tinysoc dut (
        .ui_in(ui_in),
        .uo_out(uo_out),
        .uio_in(loopback_uio_in),
        .uio_out(dut_uio_out),
        .uio_oe(dut_uio_oe),
        .ena(ena),
        .clk(clk),
        .rst_n(rst_n)
    );

    assign uio_out = dut_uio_out;
    assign uio_oe = dut_uio_oe;
    assign debug_rx_ready = dut.core.rx_ready;
    assign debug_rx_data = dut.core.rx_data;
endmodule
