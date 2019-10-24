#include <stdio.h>
#include <stdlib.h>

struct node
{
        int info;
        struct node *left;
        struct node *right;
};

typedef struct node* NODE;

NODE createBST(NODE root,int item)
{
        NODE temp=(NODE)malloc(sizeof(struct node));
        NODE prev,cur;
        temp->info=item;
        temp->left=temp->right=NULL;
        if(root==NULL)
                return temp;
        else
        {
                for(prev=NULL,cur=root; cur!=NULL;)
                {
                        prev=cur;
                        if(item<cur->info)
                                cur=cur->left;
                        else
                                cur=cur->right;
                }

                if(item<prev->info)
                        prev->left=temp;
                else
                        prev->right=temp;
                return root;
        }
}
