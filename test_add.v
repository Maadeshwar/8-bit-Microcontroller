module test_add;
  reg [7:0] a, b;
  wire [7:0] res_add = a + b;
  initial begin
    a = 8'hFF;
    b = 8'h01;
    $display("add = %x", a + b);
    $display("flag_z = %b", ((a + b) == 8'h00));
    $display("flag_z2 = %b", (res_add == 8'h00));
  end
endmodule
