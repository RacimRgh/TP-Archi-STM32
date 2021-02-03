.data
SUM: .2byte 0
RES: .2byte 0
TAB: .4byte 1, 12, 28, 4, 3

.text
.global main
.type main, %function

main:

/* ---------
	A COMPLETER
   ---------*/
   /* Récupérer l'adresse de TAB dans R1 */
   ldr r0, =TAB
   ldr r5, =RES
   /* Initialiser les registres */
   mov r1, #0
   mov r4, #0
   /* Effectuer la somme */
loop:
   cmp r1, #20
   beq end
   ldr r3, [r0, r1]
   add r4, r4, r3
   add r1, r1, #4
   b loop
   /* Mettre le résultat de la somme dans la variable SUM */
   /* */
end:
   STR R4, [R5]

stop: 	B stop
		BX LR
.end




