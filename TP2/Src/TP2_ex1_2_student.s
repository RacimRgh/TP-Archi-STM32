.data
const1_64bits_p1: .word 0xFFFFFFFE
const1_64bits_p2: .word 0x02000000
const2_64bits_p1: .word 0x00000011
const2_64bits_p2: .word 0x02000000
const3_64bits: .skip 8

.text
.global main
.type main, %function

main:
		/*A COMPLETER*/
		/* Const1 64 bits 1 */
		LDR R0, =const1_64bits_p1
		LDR R0,[R0]
		LDR R1, =const1_64bits_p2
		LDR R1,[R1]
		/* Const2 64 bits  */
		LDR R2, =const2_64bits_p1
		LDR R2,[R2]
		LDR R3, =const2_64bits_p2
		LDR R3,[R3]
		/* Addition poids faible normal
			et poids fort avec retenue "carry"  */
		ADD R4,R0,R2
		/* en faisant ADC R5,R1,R3 j'ai l'erreur "Error: dest must overlap one source register" */
		ADC R1,R1,R3
		

stop:   B stop
		BX LR
.end


