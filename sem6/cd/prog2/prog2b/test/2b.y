%{
    #include<stdio.h>
%}
%token NUMBER

%left '+' '-'
%left '*'
%left '/'
%left '(' ')'
%%
A: E {printf("\nResult=%d\n",$$); return 0;}
E:E'+'E {$$=$1+$3;}
 |E'-'E {$$=$1-$3;}
 |E'*'E {$$=$1*$3;}
 |E'/'E {$$=$1/$3;}
 |E'%'E {$$=$1%$3;}
 |'('E')' {$$=$2;}
 | NUMBER {$$=$1;}
;
%%

void main()
{
   printf("\nEnter an arithmetic expression:\n");
   yyparse(); 
}
void yyerror()
{
   printf("\nEntered arithmetic expression is Invalid\n\n");
}
