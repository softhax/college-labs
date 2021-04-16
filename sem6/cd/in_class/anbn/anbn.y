%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
%}
%%
S:'a'S'b'
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
