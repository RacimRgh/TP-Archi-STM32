.data
const1: .word 0x08000000
const2: .word 0x07000000
const3: .word 0x40000000
const4: .word 0x80000000
const5: .word 0x00F00000
const6: .word 0xFFFFFFFF
const7: .word 0x7F000000
const8: .word 0x0F000000

.text
.global main
.type main, %function

main:
		/* ligne 1*/
		LDR R0, =const1
		LDR R0,[R0]
		LDR R1, =const2
		LDR R1,[R1]
		ADD R2,R0,R1
		SUB R3,R0,R1
		/* ligne 2*/
		LDR R0, =const3
		LDR R1,[R0]
		LDR R0,[R0]
		ADD R2,R0,R1
		/* ligne 3*/
		LDR R1, =const4
		LDR R1,[R1]
		SUB R2,R0,R1
		/* ligne 4*/
		LDR R0, =const5
		LDR R0,[R0]
		LDR R1, =const6
		LDR R1,[R1]
		ADD R2,R0,R1
		/* ligne 5*/
		LDR R0, =const7
		LDR R0,[R0]
		LDR R1, =const8
		LDR R1,[R1]
		ADD R2,R0,R1
		SUB R3,R0,R1
		/* ligne 6*/
		ADD R2,R1,R0
		SUB R3,R1,R0


stop:   B stop
		BX LR
.end


