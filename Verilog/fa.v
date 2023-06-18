//full adder code: structural model
`timescale 1ns/100ps //optional
module fa (
  input wire i_a, i_b, i_c,
  output wire o_sum, o_carry
);
  wire s1, c1, c2; //internal

  assign s1 = i_a ^ i_b;
  assign o_sum = s1 ^ i_c;

  assign c2 = s1 & i_c;
  assign c1 = i_a & i_b;
  assign o_carry = c1 | c2;
endmodule

//***Testbench Module***
module testb_fa;
  reg a, b, c;
  wire sum, carry;
  fa uut ( .i_a(a), .i_b(b), .i_c(c), .o_sum(sum), .o_carry(carry));
  initial begin
    $dumpfile("fa.vcd");
    $dumpvars(); //for gtkwave display
    $monitor("a=%b, b=%b, c=%b, carry=%b, sum=%b", a, b, c, carry, sum);
    a=0; b=0; c=0; //input signals for full adder
    #10 a=0; b=0; c=1;
    #10 a=0; b=1; c=0;
    #10 a=0; b=1; c=1;
    #10 a=1; b=0; c=0;
    #10 a=1; b=0; c=1;
    #10 a=1; b=1; c=0;
    #10 a=1; b=1; c=1;
    #10 a=0; b=0; c=0;
    #10 $finish;
  end
endmodule
