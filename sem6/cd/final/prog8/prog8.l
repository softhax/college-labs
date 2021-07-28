%{
#include<stdio.h>
#include "y.tab.h"
#include<stdlib.h>
extern char *yytext;
%}

letter [A-Za-z]
digit [0-9]

%%

{letter}({letter}|{digit})* return ID;
{digit}+ {yylval=atoi(yytext); return NUM;}
[\n\t] yyterminate();
. return yytext[0];
%%

int yywrap(){}
