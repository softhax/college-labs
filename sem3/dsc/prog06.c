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

NODE insertEnd(NODE START,int item,int i,int j)
{
    NODE temp=(NODE)malloc(sizeof(struct node)),cur;
    temp->info=item;
    temp->row=i;
    temp->col=j;
    temp->left=temp;


}
