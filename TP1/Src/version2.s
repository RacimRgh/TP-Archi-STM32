.data
SUM: .2byte 0

.text
.global main
.type main, %function

main:
	/* Initialisation des registres et addition */
	mov r0, #1
	mov r2, #3
	mov r3, #5
	add r4, r0, r2
	add r4, r4, r3
	/* Récupération de l'adresse de SUM, et stockage du résultat*/
	ldr r1, =SUM
	str r4, [r1]
end:
   STR R4, [R5]

stop: 	B stop
		BX LR
.end




