    AREA RESET,CODE
	ENTRY

	LDR R0,=ARRAY
	LDMIA R0,{R1-R10};	Copy from flash to sram using registers
	MOV SP,#0x40000000
	STMIA SP,{R1-R10}
	MOV R10,#0x40000000;	Starting memory address of array
	MOV R1,#10;		Total Elements
	SUB R1,#1;		Total iterations = N-1

LOOP1
	MOV R2,R1;		No of comparisons in a given pass = no of passes left
	MOV R4,R10;		Set R4 = Startin memory address for every pass

LOOP2
	LDR R0,[R4];		Get first element, arr[i]
	LDR R5,[R4,#4];		Get next element, arr[i+1]
	CMP R0,R5
	BLS SKIP;		If arr[i]<arr[i+1], skip
	MOV R6,R0;		Else swap arr[i] and arr[i+1]
	MOV R0,R5
	MOV R5,R6
	STR R0,[R4]
	STR R5,[R4,#4]

SKIP
	ADD R4,#4
	SUBS R2,#1;		Go to next comparison
	BNE LOOP2
	SUBS R1,#1;		Go to next comparison
	BNE LOOP1

STOP B STOP


ARRAY DCD 2,7,4,5,11,18,3,15,8,0
	END
