
.data
VAL: .word 0x87654321


.text
.global main
.type main, %function

main:

		MOV R0, #0x3A
		MOV R1, #0x0F
		MOV R2, #0x10
		AND R1, R0, R1 // R1 = ?
		AND R0, R0, R2 // R0 = ?
		ORR R0, R1, R0 // R0 = ?
		BIC R0, R0, R2 // R0 = ?
		 
		//suite
		LDR R0, =VAL
		LDR R0, [R0]
		MOV R1, #0xFF
		LSL R2, R1, #4 // R2 = ?
		ASR R3, R2, #2 // R3 = ?
		ASR R4, R0, #2 // R4 = ?
		LSR R4, R1, #1 // R4 = ?
		EOR R2, R4, R2 // R2 = ?
		BIC R4, R4, R1 // R3 = ?
		
stop: 	B stop
		BX LR
.end
