#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 100

char stack[SIZE];
int top=-1;

void push(char item)
{
    if(top>=SIZE-1)
	printf("\nStack Overflow !!!\n");
    else
    {
	top++;
	stack[top]=item;
    }
}

char pop()
{
    char item;
    if(top<0)
    {
	printf("\nStack Underflow\n");
	getchar();
	exit(1);
    }
    else
    {
	item=stack[top];
	top--;
	return item;
    }

}

int precedence(char symbol)
{
    if(symbol == '^')
	return 3;
    else if(symbol == '*' || symbol == '/')
	return 2;
    else if(symbol == '+' || symbol == '-')
	return 1;
    else
	return 0;
}



int isOperator(char symbol)
{   
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol== '-')
	return 1;
    else
	return 0;
}

void infixToPostfix(char infix[],char postfix[])
{
    int i=0,j=0;
    char item=infix[i];
    char x;
    push('(');
    strcat(infix,")");
    while(item!='\0')
    {
	if(item== '(')
	    push(item);
	else if( isalpha(item) || isdigit(item) )
	{
	    postfix[j]=item;
	    j++;
	}
	else if(isOperator(item)==1)
	{
	    x=pop();
	    while(isOperator(x)	== 1 && precedence(x) >= precedence (item))
	    {
		postfix[j]=x;
		j++;
		x=pop();
	    }
	    push(x);
	    push(item);
	}

	else if(item==')')
	{   
	    x=pop();
	    while(x!='(')
	    {
		postfix[j]=x;
		j++;
		x=pop();
	    }
	}

	else
	{
	    printf("\nInvalid infix expression !!!\n");
	    getchar();
	    exit(1);
	}
	i++;
	item=infix[i];
    }

    if(top>0)
    {
	printf("\nInvalid infix expression !!!\n");
	getchar();
	exit(1);
    }
    postfix[j]='\0';
}

void main()
{
    char infix[SIZE],postfix[SIZE];
    printf("Enter the infix expression : \n");
    gets(infix);
    infixToPostfix(infix,postfix);
    printf("\nPostfix Expression : \n");
    puts(postfix);
    
}



