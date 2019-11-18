#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    int col;
    int row;
    struct node *left;
    struct node *right;
};


typedef struct node* NODE;

NODE insertEnd(NODE start,int item,int i,int j)
{
    NODE temp=(NODE)malloc(sizeof(struct node)),cur;
    temp->info=item;
    temp->row=i;
    temp->col=j;
    temp->left=temp->right=NULL;
    if(start==NULL)
	return temp;
    for(cur=start;cur->right!=NULL;cur=cur->right);
    //temp->left=cur;
    cur->right=temp;
    temp->left=cur;
    return start;
}

void display(NODE start)
{
    NODE cur;
    if(start==NULL)
    {
	printf("\n\nThe List is empty !!!\n\n");
	return;
    }
    for(cur=start;cur!=NULL;cur=cur->right)
	printf("%d\t%d\t%d\t\n",cur->row,cur->col,cur->info);
}
void matDisplay(NODE start,int m,int n)
{
    NODE temp=start;
    int i,j;
    for(i=1;i<=m;i++)
    {
	for(j=1;j<=n;j++)
	{
	    if(temp!=NULL && temp->row==i && temp->col==j)
	    {
		printf("%d ",temp->info);
		temp=temp->right;
	    }
	    else
		printf("0 ");

	}
	printf("\n");

    }

}
void main()
{
    NODE start=NULL;
    int i,j,m,n,item;
    printf("Enter the size of the matrix:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements :\n");
    for(i=1;i<=m;i++)
    {
	for(j=1;j<=n;j++)
	{
	    scanf("%d",&item);
	    //printf("%d",item);
	    if(item)
		start=insertEnd(start,item,i,j);
	}
    }
    printf("\nThe non zero elements are :\n");
    printf("\nRow\tCol\tValue\n");
    display(start);
    printf("\n\nMatrix Display :\n\n");
    matDisplay(start,m,n);
}




