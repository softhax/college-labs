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
                        free(temp);
                }
                else if (root->right==NULL)
                {
                        temp=root;
                        root=root->left;
                        free(temp);
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
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->info);
}

void main()
{
        NODE root=(NODE)malloc(sizeof(struct node));
        root = NULL;
        char ch='y';
        int choice;
        do
        {                printf("Entered choice is : %d",choice);
                //system("clear");
                printf("Enter the choice of operation : \n");
                printf("1.Insert\n");
                printf("2.Delete\n");
                printf("3.Preoder\n");
                printf("4.Inorder\n");
                printf("5.Postorder\n");
                printf("6.Exit\n");
                scanf(" %d",&choice);
                switch (choice)
                {
                        case 1: {
                                int x;
                                printf("Enter the value to be inserted : ");
                                scanf("%d",&x);
                                root=createBST(root,x);
                                break;
                        }
                        case 2: {
                                int x;
                                printf("Enter the value to be deleted : ");
                                scanf("%d",&x);
                                root=del(root,x);
                                break;
                        }
                        case 3: {
                                preorder(root);
                                break;
                        }
                        case 4: {
                                inorder(root);
                                break;
                        }
                        case 5: {
                                postorder(root);
                                break;
                        }
                        case 6: {
                                exit(0);
                        }
                        default: {
                                printf("Invalid choice of operation ...\n");
                                break;
                        }
                }
                printf("Do you want to continue ? (y or n)\n");
                scanf(" %c",&ch);
        } while(ch=='y'||ch=='Y');
}
