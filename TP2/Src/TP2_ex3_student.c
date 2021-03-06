
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char string1[]= "Vive CY CErgy Paris Universiteeee!";
int count_e(char* tab);
int count_e_asm(char* tab);
int nb_e_c =0, taille;

int main (void){
	taille = strlen(string1);
	//Init Tab Content randomly
//	nb_e_c = count_e(string1);
	int success = count_e_asm(string1);
	//Infinite loop
	while(1){
	}
	
	return 0;
}

int count_e(char* tab){  
	/*A COMPLETER */
	char ch;
	for(int i=0 ; i < taille ; i++)
	{
		ch = string1[i];
		if(string1[i] == 'e')
			nb_e_c = nb_e_c + 1;
	}
	asm("LDR r0,=nb_e_c");
	asm("LDR r0,[r0]");
}

int count_e_asm(char* tab){
	// Compteur de 'e'
	asm("LDR r3,=nb_e_c\n\t"
		"LDR r3, [r3]\n\t"
	);
	// Taille de la chaine
	asm("LDR r4,=taille\n\t"
		"LDR r4, [r4]\n\t"
		);
	// Adresse du tableau et compteur de parcours
	asm("LDR r0, =string1\n\t"
		"MOV r2, #0\n\t");
	// Boucle de parcours et vérification si caractère == 'e' == 101 (ascii)
	asm(
	"loop:\n\t"
		"LDRB r1, [r0,r2]\n\t"
		"CMP r1, #101\n\t"
		"BNE check_cpt\n\t"
		// si caractère égale on incrémente le compteur de e
		"ADD r3,r3,#1\n\t"
	"check_cpt:\n\t"
		// Vérification si fin de chaine
		"ADD r2,r2,#1\n\t"
		"CMP r2,r4\n\t"
		"BNE loop\n\t"
	);
	asm("LDR r5, =nb_e_c\n\t"
		"STR r3, [r5]\n\t"
	);
	
 			 
	return 0;
}
