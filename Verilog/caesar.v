module caesar (
  input wire clk,        // Clock signal
  input wire rst,        // Reset signal
  input wire [7:0] key,  // Key for encryption/decryption
  input wire [7:0] data_in,  // Input data to be encrypted/decrypted
  output reg [7:0] data_out  // Encrypted/decrypted output data
);

  // Define constant parameters
  parameter OFFSET = 3;  // Offset for shifting characters in the cipher

  // Registers for storing intermediate values
  reg [7:0] shifted_data;
  reg [7:0] encrypted_data;

  always @(posedge clk or posedge rst) begin
    if (rst) begin
      // Reset the registers to their initial values
      shifted_data <= 0;
      encrypted_data <= 0;
    end else begin
      // Shift the input data by the specified offset
      shifted_data <= data_in + OFFSET;

      // Encrypt/decrypt the shifted data using the key
      encrypted_data <= shifted_data ^ key;
    end
  end

  // Assign the output data to the encrypted/decrypted value
  assign data_out = encrypted_data;

endmodule
