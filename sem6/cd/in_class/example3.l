%{
#include<stdio.h>
int variables=0,keywords=0;
%}
%%
"const"|"int"|"float"|"double" {keywords++;}
[a-zA-Z_][a-zA-Z0-9_]* {variables++;}
[ \n] ;
%%
int main()
{
	printf("Enter the string\n");
	yylex();
	printf("variables=%d,keywords=%d\n",variables,keywords);
}
