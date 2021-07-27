%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int yylex();
int yyerror();
%}
%%
S:A B
 ;
A:'a'A'b'
 |
 ;
B:'b'B'c'
 |
 ;
%%
int main()
{
yyparse();
printf("\n Valid String\n");
}

int yyerror()
{
printf("INVALID!!!\n");
exit(0);
}
