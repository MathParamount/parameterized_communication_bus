# Overview

he project roadmap is:

bus_if -> arbiter -> bus_controller -> slave_reg


The project interface needs 11 input and 8 output:

In slave chunk inputs are: 
read_addr;
read_addr_prot -> is a vector with 3 bits to tell the privilege, bit2 (standard/privilege), bit1 (secure/non-secure), bit0 (data/instruction);
read_addr_valid -> when the read address is valid and ready on bus;
read_addr_ready -> when the slave can accept this address; 

read_data_ready -> when slave can accept the data;

write_addr;
write_addr_prot;
write_addr_valid;

write_data;
write_data_strb -> tell what's the specific data bus write bytes has valid info. Allowing parcial write of words.
write_data_valid;
write_resp_ready -> send back a response after committing writes to say if the write failed.

slave chunk outputs are:

read_addr_ready;
read_data;
read_data_resp;
read_data_valid;

write_addr_ready;
write_data_ready;

write_resp;
write_resp_valid;


# Architecture

# Observations

# Conclusion
