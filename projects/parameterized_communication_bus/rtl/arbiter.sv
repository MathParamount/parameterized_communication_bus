`ifndef ARBITER_SV
`define ARBITER_SV

module arbiter (bus_if m, bus_if s);
  
  //interconnection
  assign s.valid = m.valid;
  assign s.read = m.read;
  assign s.write = m.write;
  assign s.addr = m.addr;
  assign s.write_data = m.write_data;
    
  assign m.ready = s.ready;
  assign m.read_data = s.read_data;
     
endmodule

`endif
