.data
TAB: .skip 20

.text
.global main
.type main, %function

main:
/* ---------
   ---------
   Récupérer l'adresse de TAB dans R1 */
   ldr r0, =TAB
   /* Initialiser r1 à 0, l'indice courant */
   mov r1, #1
   mov r2, #0
   /* Remplir le tableau */
loop:
   cmp r1, #10
   beq stop
   str r1, [r0, r2]
   add r1, r1, #1
   add r2, r2, #2
   b loop

stop: 	B stop
		BX LR
.end




