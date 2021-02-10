.data /*mot clé de déclaration d'une zone de données */
SIZE:		.byte 7 /*Taille chaine -1 */
Hello: 		.asciz "Bonjour"
Hello2: 	.asciz "Bonjour"
SAME:   	.byte 0

.text
.global main
.type main, %function

main:
	/* Chargement des variables */
	LDR R0,=Hello
	LDR R1,=Hello2
	LDR R2,=SIZE
	LDRB R2,[R2]
	/* on initialise un compteur */
	MOV R3, #0
loop:
	/* Si taille = compteur alors mots égaux, on va vers égale pour changer la variable SAME*/
	CMP R3,R2
	BEQ egale
	/* On charge une lettre de chaque mot */
	LDRB R4,[R0,R3]
	LDRB R5,[R1,R3]
	ADD R3,R3,#1
	CMP R4,R5
	BEQ loop
	/* Si on trouve un caractère différent, on saute vers la fin, et SAME reste à 0 */
	B stop

	/* Si la variable SAME a changé vers 0, on arrete (on a trouvé une lettre différente) */
egale:
	LDR R6,=SAME
	MOV R7,#1
	STRB R7,[R6]

stop:   B stop
		BX LR
.end










