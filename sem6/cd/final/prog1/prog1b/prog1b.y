%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int yylex();
int yyerror();
%}
%%
S : A B
  ;
A : 'a' A 'b'
  |
  ;
B : 'b' B 'c'
  |
  ;
%%

int main()
{
    printf("Enter the string:\n");
    yyparse();
    printf("\nValid String\n");
}

int yyerror()
{
    // This function is called in case of error
    printf("\nInvalid String!!!\n");
    exit(0);
}
