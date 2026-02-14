`ifndef MASTER_REG_SV
`define MASTER_REG_SV

module master_reg(
    input logic clk, 
    input logic reset,
    bus_if.master busa
);
    
    //states
    localparam [1:0] ST_IDLE = 2'b00;
    localparam [1:0] ST_ADDR_PHASE = 2'b01;
    localparam [1:0] ST_DATA_PHASE = 2'b10;
    
    reg [1:0] state;
    reg [1:0] next_state;
    
    //inner registers
    logic write_r, valid_r, read_r;
    logic [15:0] addr_r;
    logic [31:0] write_data_r;
    
    //middle variables
    logic next_valid_r, next_read_r, next_write_r;
    logic [15:0] next_addr_r;
    logic [31:0] next_write_data_r;
        
    //connecting with interface
    assign busa.valid      = next_valid_r;
    assign busa.read       = read_r;
    assign busa.write      = write_r;
    assign busa.addr       = addr_r;
    assign busa.write_data = write_data_r;
    
    //combinational logic
    always_comb begin
        // Default values
        next_state = state;
        next_valid_r = 1'b0;
        next_read_r = 1'b0;
        next_write_r = 1'b0;
        
        //maintain
        next_addr_r = addr_r;
        next_write_data_r = write_data_r;
        
        case (state)
            ST_IDLE: begin
            	next_state = ST_ADDR_PHASE;
            end
            
            ST_ADDR_PHASE: begin
		next_valid_r = 1'b1;
		
		//switch one to change from read to write
                next_read_r = 1'b1;
        	next_write_r = 1'b0;
                
                next_addr_r = 16'h0001;
                next_write_data_r = 32'hDEACBEFF;
                
                if (busa.ready) begin
                        next_state = ST_DATA_PHASE;
                end
            end
            
            ST_DATA_PHASE: begin
            	next_valid_r = 1'b1;
            	
                //master don't do nothing, only look to read;
                
                if(write_r) begin
                	next_write_data_r = '0;
		end
                
                if (busa.ready) begin
                    next_state = ST_IDLE;
                end
              end
              
            default: begin
            	next_state = ST_IDLE;
            	next_valid_r = 1'b0;
        	next_read_r = 1'b0;
        	next_write_r = 1'b0;
            end
            
        endcase
    end
    
    //sequential logic
    always_ff @(posedge clk or negedge reset) begin
        if (!reset) begin
            write_r <= 1'b0;
            write_data_r <= '0;
            state <= ST_IDLE;
            valid_r <= 1'b0;
            
            read_r <= '0;
            addr_r <= '0;
        end
        else begin        
            state <= next_state;
            write_r <= next_write_r;
            read_r <= next_read_r;
    	    addr_r <= next_addr_r;
    	    write_data_r <= next_write_data_r;
    	    valid_r <= next_valid_r;
        end
    end

endmodule

`endif
