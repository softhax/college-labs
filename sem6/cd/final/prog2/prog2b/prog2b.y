%{
    #include<stdio.h>
    int flag=0;
    void yyerror();
    int yylex();
%}
%token NUMBER

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithmeticExpression: E{ printf("\nResult=%d\n",$$); return 0;}
E   :	E'+'E {$$=$1+$3;}
    |	E'-'E {$$=$1-$3;}
    |	E'*'E {$$=$1*$3;}
    |	E'/'E {$$=$1/$3;}
    |	E'%'E {$$=$1%$3;}
    |	'('E')' {$$=$2;}
    |	NUMBER {$$=$1;}
    ;
%%

void main()
{
   printf("\nEnter an arithmetic expression:\n");
   yyparse();
   if(flag==0)
	printf("\nEntered Arithmetic Expression is Valid\n");
 
}
void yyerror()
{
   printf("\nEntered arithmetic expression is Invalid\n");
   flag=1;
}