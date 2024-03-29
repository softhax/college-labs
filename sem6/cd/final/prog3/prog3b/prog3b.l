%{
    #include "y.tab.h"
    extern yylval;
%}

alpha [A-Za-z]
digit [0-9]

%%
for			    {return FOR;}
{digit}+		    {return NUM;}
{alpha}({alpha}|{digit})*   {return ID;}
"<="			    {return LE;}
">="			    {return GE;}
"=="			    {return EQ;}
"!="			    {return NE;}
[\t \n]			    ;
.			    {return yytext[0];}
%%
