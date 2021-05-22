%{
#include<stdio.h>
#include<stdlib.h>
int count=0;
%}
%token FOR LR RR LC RC VAR SPACE NUM
%%
S : I
  ;
I : FOR A B {count++;}
  ;
A : LR E';'E';'E RR
  ;
E : VAR Z NUM 
  | VAR Z VAR 
  | VAR U 
  | SPACE 
  |
  ;
Z : '='|'>'|'<'|'<''='|'>''='|'=''+'|'=''-' 
  ;
U : '+''+'|'-''-'
  ;
B : LC I RC
  | ;
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
