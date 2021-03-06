#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 10

int fibo(int x, int y);
int fibo_suite[TAB_SIZE]={0};
void fibo_asm();
int x=0, y=1;


int main (void){
	
	// Perform call to fibo function 
	//int res = fibo(0,1);
	fibo_asm(x,y);
	
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

void fibo_asm(){
	//Adresse du tableau
	asm("LDR r0, =fibo_suite");
	// Récupération de x et y et initialisation du compteur (debut:2*4 octets)
	asm("MOV r1,#8\n\t"
		"LDR r2, =x\n\t"
		"LDR r3, =y\n\t"
		"LDR r2, [r2]\n\t"
		"LDR r3, [r3]\n\t"
	);
	// Stockage des 2 premières valeurs du tableau
	asm("STR r2,[r0]\n\t"
		"STR r3,[r0,#4]\n\t");
	// Effectuer la somme de fibonacci
	asm("loop:\n\t"
		"ADD r4,r3,r2\n\t"
		"MOV r2,r3\n\t"
		"MOV r3,r4\n\t"
		"STR r4,[r0,r1]\n\t"
		"ADD r1,r1,#4\n\t"
		"CMP r1,#40\n\t"
		"BNE loop\n\t"
	);
}

