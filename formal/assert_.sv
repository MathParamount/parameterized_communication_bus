module assert_(input logic clk,input logic reset, bus_if.master busa, bus_if.slave busc);
	
	import axi_pkg::*;

	//master assertions

	//Denied jump to states didn't specified in FSM
	a_decl_m: assert property (@(posedge clk)
		(busa.state == ST_IDLE)
		|=>
		!(busa.state == ST_DATA_PHASE)
	);

	b_decl_m: assert property (@(posedge clk)
		(busa.state == ST_ADDR_PHASE)
		|=>
		!(busa.state == ST_IDLE)
	);
	
	//In reset state the internal signal shouldn't be active
	c_decl_m: assert property (@(posedge clk)
		(reset)
		|=>
		(!busa.write && !busa.read && !busa.write_data && !busa.addr)
	);

	//ensure that metastability problems and false state won't happen
	d_decl_m: assert property (@(posedge clk)
		!(busa.state inside {ST_IDLE,ST_ADDR_PHASE,ST_DATA_PHASE})
		|=>
		(busa.state == ST_IDLE)
	);

	//slaver assertion
	
	a_decl_s: assert property(@(posedge clk)
		(busc.state == ST_IDLE)	
		|=>
		!(busc.state == ST_DATA_PHASE)
	);

	b_decl_s: assert property(@(posedge clk)
		(busc.state == ST_ADDR_PHASE)
		|=>
		!(busc.state == ST_IDLE)
	);

	c_decl_s: assert property(@(posedge clk)
		!(busc.state inside {ST_IDLE,ST_ADDR_PHASE,ST_DATA_PHASE})
		|=>
		busc.state == ST_IDLE
	);

	d_decl_s: assert property(@(posedge clk)
		!busa.write_data && !busa.valid && !busa.addr
		|=>
		!busc.read_data
	);
endmodule
