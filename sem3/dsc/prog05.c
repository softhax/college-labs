#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
        int data;
        struct node *next;
};
typedef struct node* NODE;


NODE insertBeg(NODE head,int item)
{
        NODE temp;
        temp=(NODE)malloc(sizeof(struct node));
        temp->data=item;
        if(head==head->next)
        {
                temp->next=head;
                head->next=temp;
                return head;
        }
        temp->next=head->next;
        head->next=temp;
        return head;
}

NODE insertEnd(NODE head,int item)
{
        NODE temp,cur;
        temp=(NODE)malloc(sizeof(struct node));
        temp->data=item;
        if(head->next==head)
        {
                temp->next=head;
                head->next=temp;
                return head;
        }
        cur=head->next;
        while(cur->next!=head)
                cur=cur->next;
        cur->next=temp;
        temp->next=head;
        return head;
}

void display(NODE head)
{
        NODE temp;
        if(head->next==head)
                printf("\n\nThe List is empty !!!\n\n");
        else
        {
                temp=head->next;
                while(temp!=head)
                {
                        printf("%d",temp->data);
                        temp=temp->next;
                }
        }
}

NODE reverse(NODE head)
{
        NODE prev,cur,next;
        cur=head->next;
        prev=head;
        while(cur!=head)
        {
                next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
        }
        head->next=prev;
        return head;
}

void add(NODE h1,NODE h2)
{
        NODE h,t1,t2;
        int c=0,add;
        h=(NODE)malloc(sizeof(struct node));
        h->next=h;
        h1=reverse(h1);
        h2=reverse(h2);
        t1=h1->next;
        t2=h2->next;
        while(t1!=h1)
        {
                add=t1->data + t2->data + c;
                h=insertBeg(h,add%10);
                c=add/10;
                t1=t1->next;
                t2=t2->next;
        }
        if(c!=0)
                insertBeg(h,c);
        printf("\nThe sum of the two numbers is : ");
        display(h);
        printf("\n\n");
}

void main()
{
        NODE h1,h2,h;
        int i=0;
        char first[10],second[10];
        int l1,l2;
        h1=(NODE)malloc(sizeof(struct node));
        h2=(NODE)malloc(sizeof(struct node));
        h1->next=h1;
        h2->next=h2;
        printf("\nEnter the first number : ");
        scanf("%s",first);
        printf("\nEnter the second number : ");
        scanf("%s",second);
        for(i=0; first[i]!='\0'; i++)
                h1=insertEnd(h1,first[i]-'0');
        for(i=0; second[i]!='\0'; i++)
                h2=insertEnd(h2,second[i]-'0');
        l1=strlen(first);
        l2=strlen(second);
        if(l1>l2)
                for(i=0; i<l1-l2; i++)
                        h2=insertBeg(h2,0);
        else
                for(i=0; i<l2-l1; i++)
                        h1=insertBeg(h1,0);

        printf("\n");
        display(h1);
        printf("\n\n");
        display(h2);
        printf("\n");
        add(h1,h2);
}
