`include "bus_if.sv"

timeunit 100ns;
timeprecision 100ns;

module arbiter;
  
  logic clk = 0;
  always #5 clk = ~clk;

  bus_if inter(clk);

  master m1 (.busm(inter.master_reg));
  slave  s1 (.busb(inter.slave_reg));

  //interconnection
  assign serv_valid = m1.valid;
  assign serv_read = m1.read;
  assign serv_write = m1.write;
  assign serv_addr = m1.addr;
    
  assign master_ready = s1.ready;
  assign master_read_data = s1.read_data;
    
    
  //address codificator
    
  assign slave_sel = (m1.addr[15:12] == 4'h0);
	
  if(slave_sel && m1.write) begin
       s1.mem[addr] <= write_data;
  end
  
  if(slave_sel && m1.read) begin
  		 read_data <= s1.mem[addr];
  end
  
endmodule
