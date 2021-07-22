%{
    #include <string.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <stdlib.h>
    extern int yylex();
    extern int yyparse();
    extern char* yytext;
%}

%token ID NUM
%right '=' 
%left '+''-'
%left '*''/'
%left UMINUS
%%
S: ID{push();}'='{push();} E{codegen_assign();}
;
E: E '+'{push();} T{codegen();}
|E '-'{push();} T{codegen();}
|T
;
T: T '*'{push();} F{codegen();}
|T '/'{push();} F{codegen();}
|F
;
F: '(' E ')'
|'-'{push();} F{codegen_umin();} %prec UMINUS
|ID{push();}
|NUM{push();}
;
%%

char st[100][10];
int top = 0;
char i_[2] = "0";
char temp[3] = "t";
char temp2[3]= "R";
char temp3[3]= "R";
int ctr = 0;

int main()
{
    int push();
    int codegen();
    int codegen_umin();
    int codegen_assign();
    printf("Enter the expression:");
    yyparse();
}

int push()
{
    strcpy(st[++top], yytext);
}

int codegen()
{
    if(st[top][0]=='R' && st[top-2][0]=='R'){
        strcpy(temp,st[top-2]);
        strcpy(temp2,st[top]);
    }
    else if(st[top][0]=='R'){
        strcpy(temp,"R");
        strcat(temp,i_);
        i_[0]++;
        strcpy(temp2,st[top]);
        printf("MOV %s,%s\n",temp,st[top-2]);
    }
    else if(st[top-2][0]=='R'){
        strcpy(temp2,"R");
        strcat(temp2,i_);
        i_[0]++;
        strcpy(temp,st[top-2]);
        printf("MOV %s,%s\n",temp2,st[top]); 
    }
    else{
        strcpy(temp, "R");
        strcat(temp, i_);
        i_[0]++;
        strcpy(temp2, "R");
        strcat(temp2, i_);
        /*i_[0]++;
        strcpy(temp3, "R");
        strcat(temp3, i_);*/
        printf("MOV %s,%s\n",temp,st[top-2]);
        printf("MOV %s,%s\n",temp2,st[top]);
    }
    if(strcmp(st[top-1],"+")==0){
        printf("ADD ");
    }
    else if(strcmp(st[top-1],"-")==0){
        printf("SUB ");
    }
    else if(strcmp(st[top-1],"*")==0){
        printf("MUL ");
    }
    else if(strcmp(st[top-1],"/")==0){
        printf("DIV ");
    }
    printf("%s,%s\n", temp2, temp);
    top -= 2;
    strcpy(st[top], temp2);
    i_[0]++;
}

int codegen_umin()
{
    strcpy(temp, "R");
    strcat(temp, i_);
    printf("%s = - %s\n", temp, st[top]);
    top--;
    strcpy(st[top], temp);
    i_[0]++;
}

int codegen_assign()
{
    printf("STR %s,%s\n", st[top], st[top-2]);
    top -= 2;
}

int yyerror(char* s)
{
    printf("\nExpression is invalid\n");
}

