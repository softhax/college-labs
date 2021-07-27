%{
#include<stdio.h>
int lines=0;
int words=0;
int characters=0;
int whitespaces=0;
%}

letter [a-zA-Z]
newline [\n]
whitespace [ \t]

%%
"exit" {
    return 0; 
}

{letter}+ {
    
    words++;
    characters+=yyleng;
}
{newline} {
    lines++;
}
{whitespace} {
    whitespaces++;
}
%%
int main()
{
	printf("\n\nPROGRAM 1A ---- Token Scanner\n\n");
	printf("NOTE : Input \"exit\" or press Ctrl+D to exit the execution...\n\n");
	printf("Enter the string\n");
	yylex();
	printf("\n\nResult : \n--------------\nNumber Of Words = %d\nNumber Of Lines=%d\nNumber Of Characters=%d\nNumber Of Whitespaces=%d\n",words,lines,characters,whitespaces);
}

