all:
	verilator --cc --exe --build -j 0 -Wall --trace-fst csrc/dual_cntrl.cpp vsrc/top.v
sim: all
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	obj_dir/Vtop
	gtkwave wave.fst

include ../Makefile
