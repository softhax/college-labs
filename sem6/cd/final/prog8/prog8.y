%{
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern char *yytext;

// Stack of height 100 and width 10. Each level is supposed to be an expression
char st[100][10];

// Represents top of the stack
int top=0;
char i_[2]="0";
char temp[2]="t";

void push();
void codegen();
void codegen_umin();
void codegen_assign();
%}

/* Definition of tokens. Will be used by the lexer  */
%token ID NUM

/* Precedence */
%right '='
%left '+' '-'
%left '*' '/'
%left UMINUS


%%
    start   : S {printf("valid \n");exit(0);}
    
    S	    : ID{push();} '='{push();} E{codegen_assign();}
	    ;
    
    E	    : E'+'{push();} T{codegen();} /* Push + to stack, Run codegen for T */
	    | E'-'{push();} T{codegen();} /* Push - to stack, Run codegen for T */
	    | T
	    ;
    
    T	    : T'*'{push();} F{codegen();} /* Push * to stack, Run codegen for F */
	    | T'/'{push();} F{codegen();} /* Push / to stack, Run codegen for F */
	    | F
	    ;
    
    F	    : '(' E ')'
	    | '-'{push();} F{codegen_umin();} %prec UMINUS  /* Push - to stack, Run codegen_umin() for F  */
	    | ID{push();}				    /* Push identifier to stack as it is */
	    | NUM{push();}				    /* Push number to stack as it is */
	    ;
%%


int main()
{
    printf("Enter the expression : ");
    yyparse();
    exit(0);
}
void push()
{
    printf("push : %s\nstack : ",yytext);
    strcpy(st[++top],yytext);
    for(int i = top;i>=0;i--)
	printf("%s ",st[i]);
    printf("\n");
}
void codegen()
{
    printf("codegen() start : %s\n",yytext);
    strcpy(temp,"t");
    strcat(temp,i_);
    printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
    top-=2;
    strcpy(st[top],temp);
    i_[0]++;
    printf("stack : ");
    for(int i = top;i>=0;i--)
	printf("%s ",st[i]);
    printf("\n");
}

void codegen_umin()
{

    printf("codegen_umin() start %s\n",yytext);
    strcpy(temp,"t");
    strcat(temp,i_);
    printf("%s = -%s\n",temp,st[top]);
    top--;
    strcpy(st[top],temp);
    i_[0]++;
    printf("stack : ");
    for(int i = top;i>=0;i--)
	printf("%s ",st[i]);
    printf("\n");
}
void codegen_assign()
{

    printf("codegen_assign() start : %s\n",yytext);
    printf("%s = %s\n",st[top-2],st[top]);
    top-=2;
    printf("stack : ");
    for(int i = top;i>=0;i--)
	printf("%s ",st[i]);
    printf("\n");
}

int yyerror(){
    printf("Invalid expression\n");
    exit(0);
}
