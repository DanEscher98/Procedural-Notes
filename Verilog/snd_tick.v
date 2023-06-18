//full adder code: structural model
`timescale 1ns/100ps //optional
module snd_tick (a, b, out);
  input a, b;
  output out;
  wire s1;
  not g0(s1, b);
  nor g1(out, s1, a);
endmodule

//***Testbench Module***
module testb;
  reg a, b;
  wire out;
  snd_tick uut (.a(a), .b(b), .out(out));
  initial begin
    $dumpfile("snd_tick.vcd");
    $dumpvars(); //for gtkwave display
    $monitor("a=%b, b=%b, out=%o", a, b, out);
    #0 a=0; b=0; //input signals for full adder
    #1 a=1; b=0;
    #1 a=0; b=1;
    #1 a=1; b=1;
    #1 $finish;
  end
endmodule
