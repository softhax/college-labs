%{
#include<stdio.h>
#include<stdlib.h>
int count=0;
%}

%token FOR LPAREN RPAREN LF RF EXP SPACE NUM

%%
S:I
;

I:FOR A B {count++;}
;

A:LPAREN E';'E';'E RPAREN
;

E:EXP Z NUM
|EXP Z EXP
|EXP U
|SPACE
|
;

Z:'='|'>'|'<'|'<''='|'>''='|'=''+'|'=''-'
;

U:'+''+'|'-''-' 
;

B:LF B RF
|I
|EXP
|EXP SPACE I
|
;

%%

int main(){
    yyparse();
    printf("\ncount of for is %d\n",count);
    return 1;
}

int yyerror(){
    printf("\n Invalid \n");
    exit(0);
}
