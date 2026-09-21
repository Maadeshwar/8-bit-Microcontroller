`default_nettype none

module tt_um_tinysoc (
    input  wire [7:0] ui_in,    // Dedicated inputs: Instruction Input
    output wire [7:0] uo_out,   // Dedicated outputs: Program Counter (Address)
    input  wire [7:0] uio_in,   // IOs: Input path
    output wire [7:0] uio_out,  // IOs: Output path
    output wire [7:0] uio_oe,   // IOs: Enable path (active high: 1=output, 0=input)
    input  wire       ena,      // always 1 when the design is powered
    input  wire       clk,      // clock
    input  wire       rst_n     // reset_n - low to reset
);

    // Instantiate the CPU Core
    cpu_core core (
        .clk(clk),
        .rst_n(rst_n),
        .ena(ena),
        .instr_in(ui_in),
        .pc_out(uo_out),
        .uio_in(uio_in),
        .uio_out(uio_out),
        .uio_oe(uio_oe)
    );

endmodule
