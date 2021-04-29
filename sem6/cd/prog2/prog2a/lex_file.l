%{
#include<stdio.h>
int pos=0,neg=0,posfrac=0,negfrac=0;
%}
%%
[-][0-9]*[.]?[0-9]+[/][-][0-9]*[.]?[0-9]+ {posfrac++;}
[+]?[0-9]*[.]?[0-9]+[/][+]?[0-9]*[.]?[0-9]+ {posfrac++;}
[+]?[0-9]*[.]?[0-9]+[/][-][0-9]*[.]?[0-9]+ {negfrac++;}
[-][0-9]*[.]?[0-9]+[/][+]?[0-9]*[.]?[0-9]+ {negfrac++;}
[+]?[0-9]*[.][0-9]+ {posfrac++;}
[-][0-9]*[.][0-9]+ {negfrac++;}
[+]?[0-9]+ {pos++;}
[-][0-9]+ {neg++;}
\n return 0;
%%
int main()
{
printf("Enter the numbers\n");
yylex();
printf(" Number of \n Positive integers = %d \n Negative integers = %d \n Positive fractions = %d \n Negative fractions = %d \n",pos,neg,posfrac,negfrac);
}
