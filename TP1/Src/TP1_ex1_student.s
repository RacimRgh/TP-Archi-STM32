.data
VALEUR_SUP30: .byte 0
SUM: .2byte 0
RES: .2byte 0
TAB: .4byte 1, 12, 28, 4, 3

.text
.global main
.type main, %function

main:
/* ---------
   ---------
   Récupérer l'adresse de TAB dans R1 */
   ldr r0, =TAB
   ldr r5, =RES
   /* Initialiser les registres à 0 pour faire la somme
   r1 contient l'indice courant, et r4 le cumul de la somme */
   mov r1, #0
   mov r4, #0
   /* Effectuer la somme */
loop:
	/*On compare le compteur avec 20, car on a 5 valeurs de 4 bytes
	Si ==20 on arrête le parcours et on fait un branchement vers end, sinon on fait la somme
	*/
   cmp r1, #20
   beq sup30
   ldr r3, [r0, r1]
   add r4, r4, r3
   add r1, r1, #4
   b loop
   /* Vérification si la somme >= 30 */
sup30:
   cmp r4, #30
   /* Si <30 on change pas la variable car elle est déjà initialisée à 0*/
   bcc end
   /* Chargement et modification de la variable */
   ldr r6, =VALEUR_SUP30
   mov r7, #1
   str r7, [r6]
   /* Mettre le résultat de la somme dans la variable RES */
end:
   str R4, [R5]

stop: 	B stop
		BX LR
.end




