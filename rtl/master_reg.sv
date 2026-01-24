`include "bus_if.sv"

timeunit 100ns;
timeprecision 100ns;

typedef enum logic [1:0]
{
	IDLE,
	DATA_PHASE,
	ADDR_PHASE
} state_t;

//initial state
state_t state = IDLE;


module master_reg
(
	input logic clk, bus_if.master_reg busa, input logic start = 1
);

	always_ff @(posedge clk or negedge reset)
	begin
		//default
		busa.valid <= 0;
		busa.read <= 0;
		busa.write <= 0;

		//read
		case(state)
			IDLE:
				if(!start)
					begin
					busa.addr <= 16'h0010;		//correção (16'b0 ->  16'h0010 )
					busa.write_data <= 32'hDEADBEEF;		//correção (32'b0  -> 32'hDEADBEEF )
					
					busa.write <= 1;		//correção: tinha colocado read e coloquei os valores em 0
					busa.valid <= 1;

					if(busa.ready)
						begin
							state <= ADDR_PHASE;
							start <= 1;
						end

					end

			DATA_PHASE:
				if(start)
					begin
						busa.valid <= 1;

						if(busa.read)
							begin
								
								if(busa.ready)
								begin
									state <= IDLE;
									start <= 0;
								end

								busa.read_data <= addr;
							
							end
						
						else if(busa.write)
							begin
								busa.valid <= 1;

								if(busa.ready) addr <= busa.write_data;	
								
								else if(busa.reset) state <= IDLE; start <= 0;
							end

					end

			ADDR_PHASE:
				if(start)
					begin
					
					if(busa.read)
						begin
						busa.valid <= 1;
						
							busa.read_data <= addr;

							if(busa.ready)
								begin
									state <= DATA_PHASE;

								end
							
						end

					else if(busa.write)
						begin
						busa.valid <= 1;
						
						addr <= busa.write_data;
						
						if(busa.ready) state <= DATA_PHASE;
						else if (busa.reset) state <= IDLE; start <= 0;

						end

					end

	end
	
	if(busa.reset)
	{
		state = IDLE;
		start = 0;
	}
	
endmodule
