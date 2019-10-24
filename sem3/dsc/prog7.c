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

NODE findMIN(NODE root)
{
        NODE cur;
        for(cur=root; cur->left!=NULL; cur=cur->left);
        return cur;

}
NODE del(NODE root, int key)
{
        NODE temp;
        if(root == NULL)
                return root;
        if(key<root->info)
                root->left=del(root->left,key);
        else if(key>root->info)
                root->right=del(root->right,key);
        else
        {
                if(root->left==NULL && root->right==NULL)
                        root = NULL;
                else if (root->left==NULL)
                {
                        temp=root;
                        root=root->right;
                        free(temp)
                }
                else if (root->right==NULL)
                {
                        temp=root;
                        root=root->left;
                        free(temp)
                }
                else
                {
                        temp=findMIN(root->right);
                        root->info=temp->info;
                        root->right=del(root->right,temp->info);
                }
        }
        return root;
}

void preorder(NODE root)
{
        if(root==NULL) return;
        printf("%d\t",root->info );
        preorder(root->left);
        preorder(root->right);
}
void inorder(NODE root)
{
        if(root==NULL) return;
        inorder(root->left);
        printf("%d\t",root->info );
        inorder(root->right);
}
void postorder(NODE root)
{
        if(root==NULL) return;
        preorder(root->left);
        preorder(root->right);
        printf("%d\t",root->info );
}
