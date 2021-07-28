%{
#include<stdio.h>
int single_line_comments = 0;
int multi_line_comments = 0;
int flag =0;
%}

start_multiline_comment \/\*
end_multiline_comment \*\/
single_line_comment \/\/.*

%%
{single_line_comment}	    {if(flag==0)single_line_comments++;}
{start_multiline_comment}   {if(flag==0)flag=1;}
{end_multiline_comment}	    {if(flag==1){multi_line_comments++;flag=0;}}
%%

int main(int argc,char **argv){
    yyin = fopen(argv[1],"r");
    yyout = fopen("output.c","w+");
    yylex();
    printf("Number of Single Line Comments : %d\n",single_line_comments);
    printf("Number of Multi Line Comments : %d\n",multi_line_comments);
    return 0;
}
