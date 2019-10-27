#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 5

void insert(int);
void display();
void delete(int);
int htable[TABLE_SIZE];

void main()
{

	int opt,i,val;
	for(i=0;i<TABLE_SIZE;i++)
		htable[i]=-1;

	while(1)
	{
		printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: {
						printf("Enter the value to be inserted in the hash table :");
						scanf("%d",&val);
						insert(val);
						break;
					}

			case 2: {
						display();
						break;
					}

			case 3: {
						printf("Enter the value to be deleted from the hash table :");
						scanf("%d",&val);
						delete(val);
						break;
					}

			case 4: {
						exit(0);
					}

			default: {

						printf("Invalid choice of input !!!\n");
						break;
					 }
					
		}
	}

}



void delete(int val)
{
	int index,i,flag=0;
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(val+i)%TABLE_SIZE;

		if(htable[index]==val)
		{
			htable[index]=-1;
			printf("Value found at index %d\n",index);
			flag=1;
			break;
		}
	}

	if(flag==0)
		printf("Value not found in the hash table !!\n");
}


void insert(int val)
{
	int index,i,flag=0;
	for(i=0;i<TABLE_SIZE;i++)
	{
		index=(val+i)%TABLE_SIZE;
		if(htable[index]==-1)
		{
			htable[index]=val;
			flag=1;
			break;
		}
	}

	if(flag==0)
		printf("Element cannot be inserted !!!\n");
}


void display()
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
		if(htable[i]!=-1)
			printf("%d\t",htable[i]);
}