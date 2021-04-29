%{
#include<stdio.h>
int lines=0,words=0,characters=0,whitespaces=0;
%}
%%
"exit" {return 0;}
[a-zA-Z]+ {words++,characters+=yyleng;}
\n {lines++;}
[ \t] {whitespaces++;}
%%
int main()
{
	printf("Enter the string\n");
	yylex();
	printf("words=%d,lines=%d,characterss=%d,whitespaces=%d\n",words,lines,characters,whitespaces);
}
