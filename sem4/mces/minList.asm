	AREA RESET,CODE
		ENTRY
		LDR R0,=LIST
		MOV R3,#6
		LDR R1,[R0],#4
		SUB R3,R3,#1
		
LOOP 	LDR R2,[R0]
		CMP R1,R2
		BLS SKIP
		MOV R1,R2
		
SKIP	ADD R0,#4
		SUB R3,#1
		CMP R3,#0
		BNE LOOP
	
		LDR R5,=0x40000000
		STR R1,[R5]
STOP B STOP

LIST DCD &18,&21,&64,&10,&74,&2
		END
			