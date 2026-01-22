timeunit 100ns;
timeprecision 100ps;

interface bus_if (input logic clk, input logic [31:0] write_ad, output logic [31:0] read_ad, output logic Rd_clk, output logic Wr_clk, input logic [31:0] busIP_data_wr, output logic [31:0] busIP_data_rd);

modport();

endinterface : bus_int
