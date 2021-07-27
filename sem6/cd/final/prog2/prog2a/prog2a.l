%{
#include<stdio.h>
int positive_fractions = 0;
int negative_fractions = 0;
int positive_integers = 0;
int negative_integers = 0;
int incorrect_symbols = 0;
int divide_by_zero = 0;
%}

integer [+-]?[0-9]+
positive_integer "+"?[0-9]+
negative_integer "-"[0-9]+
non_zero_positive_integer "+"?[1-9][0-9]*
non_zero_negative_integer "-"[1-9][0-9]*
signed_positive_integer "+"[0-9]+
signed_negative_integer "-"[0-9]+


%%

{integer}"/0"						{divide_by_zero++;}

{integer}"."{signed_positive_integer}			{incorrect_symbols++;}
{integer}"."{signed_negative_integer}			{incorrect_symbols++;}

{positive_integer}"."{non_zero_positive_integer}	{positive_fractions++;}
{negative_integer}"."{non_zero_positive_integer}	{negative_fractions++;}
{positive_integer}"/"{positive_integer}			{positive_fractions++;}
{positive_integer}"/"{negative_integer}			{negative_fractions++;}
{negative_integer}"/"{positive_integer}			{negative_fractions++;}
{negative_integer}"/"{negative_integer}			{positive_fractions++;}
{positive_integer}					{positive_integers++;}
{negative_integer}					{negative_integers++;}

[\n]							{return 0;}
%%
    
int main(){
    printf("\nPROGRAM 2A\n");
    printf("Input Numbers:\n");
    yylex();
    printf("\n\nResult:\n-----------------------\n");
    printf("Negative Fractions = %d\n",negative_fractions);
    printf("Postive Fractions = %d\n",positive_fractions);
    printf("Negative Integers = %d\n",negative_integers);
    printf("Positive Integers = %d\n",positive_integers);
    printf("Incorrect Symbols = %d\n",incorrect_symbols);
    printf("Divide By Zero = %d \n", divide_by_zero);
}

