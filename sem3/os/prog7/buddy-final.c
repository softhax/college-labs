#include<stdio.h>
#include<stdlib.h>

struct node
{
    int size;	//size of the memory block
    int data;	//This holds the actual size of memory  that has been allocated to the process .
    int status;	//status of the memory block - 
		// 0	--->	memory block is not occupied
		// 1	--->	memory block is occupied
		// 2	--->	memory block is split into two smaller blocks
    struct node* right;
    struct node* left;
};

typedef struct node* NODE;

// This method creates a new memory block with given size and assigns the specified status to it
NODE createNewNode(int size,int status)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->size=size;
    temp->data=0;		//Changed
    temp->status=status;
    temp->left=temp->right=NULL;
    return temp;
}


//This method returns 1 if the space is available and returns 0 if it is not.
int checkSpace(NODE head,int size)
{
    if(head->size < size)   //Process is asking for a larger memory block than this current block.
	return 0;	    //Hence we cannot allot. Therefore, return 0.
    
    if(head->status==0)	    //Check if the current block is not occupied and not divided.
    {
	/*  Now here what we are checking is that whether the current block is the 
	 *  best fit for the size/memory requested by the user/process or not.
	 *  To do that we are checking whether the size requested is less than half the size of
	 *  the current memory block we are dealing with. If it is less, then we split the current
	 *  memory block into two and make them as children for current memory block. Also, we
	 *  set the status of current block to 2 to show the split that just happened.Then we 
	 *  recursively use the checkSpace method to again check for the correct memory block.
	 * */
	if(head->size/2	>=  size )
	{
	    head->status=2;
	    head->left=createNewNode(head->size/2,0);
	    head->right=createNewNode(head->size/2,0);
	    return checkSpace(head->left,size);
	}

	// The size of this block is perfect for the request and it should be allocated here.
	else
	{
	    head->status=1;
	    head->data=size;
	    return 1;
	}

    }
    
    //This block is already occupied. Hence, return 0.
    else if(head->status==1)
	return 0;

    //Entering this region means that this memory block has been split before.
    else
    {
	//Here we will be checking for the availability of the right amount of the space for
	//the requirement firstly in the left child of this block and if it is not available in
	//it then we will check for the right child.
	if(checkSpace(head->left,size))
	    return 1;
	else
	    return checkSpace(head->right,size);
    }

}


void displayMemoryTree(NODE head)
{
   if(head->status==2)
   {
	displayMemoryTree(head->left);
	displayMemoryTree(head->right);
   }
   else
       printf ("%d\t\t%d\t\t%d\n",head->size,head->status,head->data);
}


int removeAllocated(NODE head,int size)
{
    if(head->status==1)//if it it occupied
    {
	if(head->data == size)//then check that if it matches the size of block
	{
	    head->data=0;
	    head->status=0;//and remove it if it does by making status=0 ie unoccupied
	    return 1;//successful removal
	}
    }

    else if(head->status==2)
    {
	if(removeAllocated(head->left,size))
	    return 1;
	return removeAllocated(head->right,size);
    }
    return 0;
}

void makeBuddy(NODE head)
{
    if(head->status == 0    || head->status == 1)
	return;
    makeBuddy(head->left);
    makeBuddy(head->right);

    if(head->left->status==0 && head->right->status==0)
    {
	NODE temp=head->left;
	free(temp);
	temp=head->right;
	free(temp);
	head->status=0;
    }
    
}


void main()
{
    int size,choice;
    while(1)
    {
	printf("Enter the size of memory - a power of 2 : ");
	scanf("%d",&size);

	if(size & (size-1))
	    printf("Enter a power of two !!\n");
	else
	    break;
    }

    NODE head = createNewNode(size,0);

    while(1)
    {
	printf ("MEMORY SLICE\tOCCUPANCY\tHOW MUCH\n");
	displayMemoryTree (head);
	printf("\nEnter the choice :\n1.Allocate Process\n2.Deallocate Process\n3.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1: {
			printf("Enter the size of the process:");
			scanf("%d",&size);
			choice=checkSpace(head,size);
			if(choice)
			    printf("Successfully Allocated.\n");
			else
			    printf("Unable to allocate.\n");
			break;
		    }

	    case 2: {
			printf("Enter the size of the block that needs to be deallocated:");
			scanf("%d",&size);
			choice=removeAllocated(head,size);
			if(choice)
			    printf("\nSuccessfully Dellocated.\n");
			else
			    printf("Unable to Deallocate.\n");
			makeBuddy(head);
			break;
		    }

	    case 3: exit(0);

	    default : printf("Wrong Input !!\n");
		      break;


	}
    }


}

