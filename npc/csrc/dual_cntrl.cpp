#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vtop* top = new Vtop{contextp};

	contextp->traceEverOn(true);
	VerilatedFstC* tfp = new VerilatedFstC;
	top->trace(tfp, 99);
	tfp->open("wave.fst");
	
	//while (!contextp->gotFinish()) {
	for (int i=0; i<1000; ++i) {
		contextp->timeInc(1);
		
		int a = rand() & 1;
		int b = rand() & 1;
		top->a = a;
		top->b = b;
		top->eval();
		
		printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		assert(a^b == top->f);
		tfp->dump(contextp->time());
	}
	
	
	tfp->close();
	
	delete top;
	delete contextp;
	
	return 0;
}
