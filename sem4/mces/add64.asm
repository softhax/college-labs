	AREA RESET,CODE
		ENTRY
		LDR R0,=NUM1
		LDR R1,[R0]
		LDR R2,[R0,#4]
		LDR R0,=NUM2
		LDR R3,[R0]
		LDR R4,[R0,#4]
		ADDS R6,R2,R4
		ADCS R5,R1,R3
		LDR R0,=RES
		STR R5,[R0]
		STR R6,[R0,#4]
STOP B STOP
	
NUM1 DCD &BBBBBBBB,&AAAAAAAA
NUM2 DCD &CCCCCCCC,&FFFFFFFF
	AREA MEMORY,DATA
RES  DCD &0
		END
	
	
	