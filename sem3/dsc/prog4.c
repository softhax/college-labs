#include <stdio.h>
#include <stdlib.h>
struct node
{
        int coeff;
        int exp;
        struct node* next;
};

struct node* createNewNode()
{
        struct node* temp;
        temp=(struct node*)malloc(sizeof(struct node*));
        return temp;
}

void display(struct node* p)
{
        if(p==NULL)
        {
                printf("The List Is Empty !!\n");
                return;
        }
        else
        {
                struct node* temp=p;
                printf("\n");
                while (temp!=NULL) {
                        printf("%dx^%d",temp->coeff,temp->exp);
                        if(temp->next!=NULL) printf("+ ");
                        temp=temp->next;
                }
        }
}


struct node* insertRear(struct node* head,int coeff,int exp)
{
        struct node* temp;
        temp=createNewNode();
        temp->coeff=coeff;
        temp->exp=exp;
        temp->next=NULL;
        if(head==NULL)
                head=temp;
        else
        {
                struct node* temp2=head;
                while (temp2->next!=NULL)
                {
                        temp2=temp2->next;
                }
                temp2->next=temp;
        }
        return head;
}

struct node* multiply(struct node* head1,struct node* head2,struct node* head3)
{
        struct node *p,*q,*temp;
        int coeff,exp,flag=0;
        p=head1;
        q=head2;
        while (p!=NULL)
        {
                q=head2;
                while(q!=NULL)
                {
                        coeff=(p->coeff) * (q->coeff);
                        exp=(p->exp) + (q->exp);
                        temp=head3;
                        while (temp!=NULL)
                        {
                                if(temp->exp==exp)
                                {
                                        temp->coeff=(temp->coeff)+coeff;
                                        flag =1;
                                        break;
                                }
                                temp=temp->next;
                        }
                        if(!flag)
                        {
                                head3=insertRear(head3,coeff,exp);
                        }
                        flag=0;
                        q=q->next;
                }
                p=p->next;
        }
        return head3;
}

void main()
{
        int n1,n2,coeff,exp;
        printf("Enter the number of terms in the first polynomial : \n");
        scanf("%d",&n1);
        printf("Enter the number of terms in the second polynomial : \n");
        scanf("%d",&n2);
        struct node *p1,*p2,*p3;
        p1=p2=p3=NULL;
        printf("Enter the first polynomial : \n");
        while (n1)
        {
                scanf("%d%d",&coeff,&exp);
                p1=insertRear(p1,coeff,exp);
                n1--;
        }
        printf("Enter the second polynomial : \n");
        while (n2)
        {
                scanf("%d%d",&coeff,&exp);
                p2=insertRear(p2,coeff,exp);
                n2--;
        }
        p3=multiply(p1,p2,p3);
        printf("\n\nThe product of the two polynomials is :   ");
        display(p3);
        printf("\n");

}
