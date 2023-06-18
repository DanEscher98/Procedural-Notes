module jk_ff (j, k, clk, reset, q, qb);
  input j, k, clk, reset;
  output reg q, qb; //flip-flop output must be of type reg
  always @ (posedge clk) begin //flip-flop operates on rising edge of clock
    if (reset) begin
      q <= 0; //flip-flop is reset (reset=1)
      qb <= 1;
    end
    else begin
      if (j!=k) begin //flip-flop is not reset (reset=0)
        q <= j;
        qb <= k;
      end
      else if (j==1 && k==1) begin
        q <= ~q;
        qb <= ~qb;
      end
    end
  end
endmodule

//*****Counter counting 1,2,3,5,7...**********
module counter_1(clock, reset, q, qb);
  input clock, reset;
  output [0:2]q, qb; //3bits wide (must declare output as vector)
  wire ja, jc;
  and a1(ja, q[1], q[2]);
  jk_ff jk0(.j(ja), .k(q[1]), .clk(clock), .reset(reset), .q(q[0]), .qb(qb[0]));
  jk_ff jk1(.j(1'b1), .k(q[2]), .clk(clock), .reset(reset), .q(q[1]), .qb(qb[1]));
  and a2(jc, qb[0], qb[1]);
  jk_ff jk2(.j(1'b1), .k(jc), .clk(clock), .reset(reset), .q(q[2]), .qb(qb[2]));
endmodule

//*********Testbench***********************
module testcount;
  reg clock, reset;
  wire [0:2]q, qb;
  counter_1 uut(.clock(clock), .reset(reset), .q(q), .qb(qb));
  initial clock=0;
  always #1 clock=~clock; //clock for the counter
  initial begin
    $dumpfile("counter_1.vcd");
    $dumpvars(); //for gtkwave
    $monitor("Output = %b%b%b", q[0], q[1], q[2]);
    reset=1;
    #10 reset=0;
    #100 $finish;
  end
endmodule
