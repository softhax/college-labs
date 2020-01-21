	AREA RESET,CODE
		ENTRY
		LDR R0,=ARR
		MOV R4,#0x10;
		MOV R7, #0; Frequency
		MOV R1, #0;Loop Counter
		
BACK	CMP R1,#8
		BEQ STOP
		LDR R3,[R0],#4
		CMP R3,R4
		ADDEQ R7,R7,#1
		ADD R1,R1,#1
		B BACK

STOP B STOP
ARR DCD &10,&25,&35,&10,&37,&12,&10,&14
		END