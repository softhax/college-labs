	AREA RESET,CODE
		ENTRY
		LDR R0,=NUM
		LDR R1,[R0]
		MOV R4,#0
		MOV R5,#0
		
L1		ANDS R2,R1,#1
		ADDNE R4,R4,#1
		LSR R1,#01
		ADD R5,R5,#1
		CMP R5,#32
		BNE L1
		
STOP B STOP
NUM DCD &AAAA0000
		END