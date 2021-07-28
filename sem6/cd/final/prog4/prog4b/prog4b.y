%{
#include <stdio.h>
#include <stdlib.h>
int count=0;
%}

%token IF RELOP S NUMBER ID NL

%%
stmt: if_stmt NL {printf("No. of nested if statements=%d\n",count);exit(0);}
;
if_stmt : IF'('cond')''{'if_stmt'}' {count++;}
          |S
;
cond: x RELOP x 
;
x:ID | NUMBER
;
%%

#include <stdio.h>
// stuff from lex that yacc needs to know about:
extern int yylex();
extern int yyparse();
extern FILE *yyin;

int main(int argc,char **argv) {
	// open a file handle to a particular file:
	FILE *myfile = fopen(argv[1], "r");
	// make sure it is valid:
	if (!myfile) {
		printf("\nCannot open file\n");
        exit(-1);
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
}

/* For printing error messages */
int yyerror(char* s) {
	printf("\nExpression is invalid\n");
    exit(0);
}
