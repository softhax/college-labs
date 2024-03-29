/* program to recognize a nested IF statement for C language */
/* run as any other yacc prog; have iffile.c as input */
%{
    #include "y.tab.h"
    extern yylval;
%}

%%
"if" {return IF;}
[sS][0-9]* {return S;}
"<"|">"|"=="|"<="|">="|"!=" {return RELOP;}
[0-9]+ {return NUMBER;}
[a-z][a-zA-Z0-9_]* {return ID;}
\n {return NL;}
. {return yytext[0];}
%%