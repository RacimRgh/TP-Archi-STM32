#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 10

int fibo(int x, int y);
int fibo_suite[TAB_SIZE]={0};
void fibo_asm(int x, int y);


int main (void){
	
	// Perform call to fibo function 
	int res = fibo(0,1);
	
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
	
	
}
