#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 10

int fibo(int x, int y);
int fibo_suite[TAB_SIZE]={0};
void fibo_asm(int x, int y);


int main (void){
	
	// Perform call to fibo function 
	int res = fibo(0,1);
	fibo_asm(0,1);
	
	//Infinite loop
	while(1){
	}
	
	return 0;
}

int fibo(int x, int y){
	//A completer
	fibo_suite[0] = x;
	fibo_suite[1] = y;
	int tmp;
	for (int i = 2; i < TAB_SIZE ; i++)
	{
		tmp = x+y;
		x = y;
		y = tmp;
		fibo_suite[i] = y;
	}
	return y;
}

void fibo_asm(int x, int y){
	//A completer
//	int res = 0;
//	__asm ("ADD %[result], %[input_x], %[input_y]"
//	    : [result] "=r" (res)
//	    : [input_x] "r" (x), [input_y] "r" (y)
//	);
	asm (
	    "TST LR, #0x40\n\t"
	    "BEQ from_nonsecure\n\t"
	  "from_secure:\n\t"
	    "TST LR, #0x04\n\t"
	    "ITE EQ\n\t"
	    "MRSEQ R0, MSP\n\t"
	    "MRSNE R0, PSP\n\t"
	    "B hard_fault_handler_c\n\t"
	  "from_nonsecure:\n\t"
	    "MRS R0, CONTROL_NS\n\t"
	    "TST R0, #2\n\t"
	    "ITE EQ\n\t"
	    "MRSEQ R0, MSP_NS\n\t"
	    "MRSNE R0, PSP_NS\n\t"
	    "B hard_fault_handler_c\n\t"
	  );
}
