%{
#include<stdio.h>
int v=0,c=0,s=0;
%}
%%
[^aeiou] {c++;}
%%
int main()
{
	printf("Enter the string\n");
	yylex();
	printf("vowels=%d,consonants=%d,spaces=%d\n",v,c,s);
}
