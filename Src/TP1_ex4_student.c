#include <stdio.h>
#include <stdlib.h>

const int TAB_SIZE=10;

void init_tab(void);
int somme_tab_asm(void);
int tab[10]={0};
int Somme = 0, success=0;

int main (void){
	
	//Init tab Content with random values
	init_tab();
	//call to somme_tab function 
	int success = somme_tab_asm();
	//printf("\nSomme: %d", Somme);
	
	//Infinite loop
	while(1){
	}
	
	return 0;
}

void init_tab(){
		for (int i=0;i<TAB_SIZE;i++){
			tab[i]=rand()%10;
		}
}

 int somme_tab_asm(void){
	 for(int i = 0; i<TAB_SIZE; i++)
	 {
	   __asm ("ADD %[result], %[input1], %[input2]"
	     : [result] "=r" (Somme)
	     : [input1] "r" (Somme), [input2] "r" (tab[i])
	   );
	 }
	 __asm("MOV R0,%[input]"
			 :/* empty operands */
			 :[input] "r" (Somme));

	 return 0; // return 0 if success
}
