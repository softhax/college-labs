#include <stdio.h>
#include <stdlib.h>
#define max 5

struct stack
{
        int st[max];
        int top;
};

void init(struct stack*p)
{
        p->top=-1;
}

void push(struct stack *p,int num)
{
        if(p->top >= max-1)
                printf("\nSTACK OVERFLOW !!\n\n");
        else
        {
                p->top++;
                p->st[p->top]=num;
        }
}

int pop(struct stack *p)
{
        int num=-1;
        if(p->top==-1)
                printf("\nSTACK UNDERFLOW !!\n\n");
        else
        {
                num=p->st[p->top];
                p->top--;
        }
        return num;
}

void display(struct stack p)
{
        if(p.top==-1)
        {
                printf("\n\nSTACK IS EMPTY !!!\n\n");
        }
        else
        {
                printf("\n");
                for(int i=p.top; i>=0; i--)
                {
                        printf("\n%d",p.st[i]);
                        if(i==p.top)
                                printf("<--");
                }
                printf("\n");
        }
}

void thirdFromTop(struct stack *p)
{
        int y,num;
        struct stack temp;
        temp.top=-1;
        if((p->top)<2)
                printf("\n\nINSUFFICIENT ELEMENTS !!!\n");
        else
        {
                for(int i=0; i<2; i++)
                {
                        num=pop(p);
                        push(&temp,num);
                }
                y=pop(p);
                printf("Third from top is %d.\n\n",y);
                push(p,y);
                for(int i=0; i<2; i++)
                {
                        num=pop(&temp);
                        push(p,num);
                }
        }
}

void thirdFromBottom(struct stack *p)
{
        int i,y,num;
        struct stack temp;
        temp.top=-1;
        if((p->top)<2)
                printf("\n\nINSUFFICIENT ELEMENTS !!!\n\n");
        else
        {
                for(i=p->top; i>2; i--)
                {
                        num=pop(p);
                        push(&temp,num);
                }
                y=pop(p);
                printf("\n\nThird from bottom is %d.\n\n",y);
                push(p,y);
                for(i=temp.top; i>=0; i--)
                {
                        num=pop(&temp);
                        push(p,num);
                }
        }
}

void popN(struct stack *p,int n)
{
        if((p->top)<n-1)
                printf("\n\nINSUFFICIENT ELEMENTS !!!\n\n");
        else
        {
                int k=n;
                while(k--)
                        pop(p);
        }
}

void main()
{
        struct stack s;
        init(&s);
        char ch;
        do
        {
                int choice;
                system("clear");
                printf("Enter your choice of operation : \n1.Push\n2.Pop\n3.Display\n4.Display Third Element From Top\n4.Display Third Element From Bottom\n5.Pop n elements\n");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                {
                        printf("\nEnter the value of to be pushed : ");
                        int x;
                        scanf("%d",&x);
                        push(&s,x);
                        break;
                }
                case 2:
                {
                        pop(&s);
                        break;
                }
                case 3:
                {
                        display(s);
                        break;
                }
                case 4:
                {
                        thirdFromTop(&s);
                        break;
                }
                case 5:
                {
                        thirdFromBottom(&s);
                        break;

                }
                case 6:
                {
                        int n;
                        printf("\n\nEnter the value of n : \n");
                        scanf("%d",&n);
                        popN(&s,n);
                        break;
                }
                default:
                {
                        printf("\n\nInvalid choice of operation !!!\n\n");
                        break;
                }
                }
                printf("Do you want to continue ? (y or n)\n");
                scanf(" %c",&ch);
        } while(ch=='y' || ch== 'Y');
}
