.data
N:		.byte 5  /*Taille */
tab:	.byte 14, 25, 2, 16, 5 /*déclaration d'un tableau tab  */

.text
.global main
.type main, %function

main:
		LDR R0,=N /*taille*/
		LDRB R0, [R0]
		LDR R1,=tab
		/* Compteur */
		MOV R2, #0
		SUB R0,R0,#1
loop:
		/*Si compteur = taille -11 alors fin du programme
		et ce pour ne pas vérifier la dernière valeur et celle d'après qui ne fait pas partie du tableau*/
		CMP R2,R0
		BEQ stop
		/* Comparer tab[compteur] et tab[compteur+1]*/
		LDRB R3,[R1,R2]
		ADD R2,R2,#1
		LDRB R4,[R1,R2]
		CMP R3,R4
		/* Si inferieur alors continuer, sinon permuter*/
		BLT loop
		/* Permutation */
		STRB R3,[R1,R2]
		SUB R2,R2,#1
		STRB R4,[R1,R2]
		/* Si on est pas à l'indice 0, revenir en arrière pour traiter la valeur précédente dans le nouveau tableau, sinon continuer */
		CMP R2,#0
		BEQ loop
		SUB R2,R2,#1
		B loop

stop:   B stop
		BX LR
.end



