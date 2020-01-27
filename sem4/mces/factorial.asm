    AREA RESET,CODE
	ENTRY
	LDR R0,=INPUT
	BL FACT;		Call subroutine FACT
	LDR R1,=0x40000000;	RAM area
	STR R3,[R1] ;		Store result in R3 to RAM
STOP B STOP

FACT	LDR R2,[R0];		get num in R2
	CMP R2,#00
	BEQ END1
	MOV R3,R2;		result=num

LOOP	SUB R2,#01;		num=num-1
	CMP R2,#00
	MULNE R3,R2,R3
	BNE LOOP
	MOV PC,LR
END1
	MOV R3,#01
END2	
	MOV PC,LR;		return from subroutine

INPUT DCD &05
    END


