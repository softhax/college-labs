#include<stdio.h>
#include<stdlib.h>


int process;
int resource;
int requestedBy;

int available[10];
int completed[10]={0};
int request[10];
int safeSequence[10];


int max[10][10];
int need[10][10];
int allocation[10][10];

int safetyAlgorithm()
{
    int count1=0,count2=0,k=0,safecount=0;
    int flag=1; 

    while(count1!=process)
    {
	count2=count1;
	for(int i=0;i<process;i++)
	{
	    for(int j=0;j<resource;j++)
	    {
		if(need[i][j] <= available[j])
		    k++;
	    }

	    if(k==resource && completed[i]==0)
	    {
		safeSequence[safecount++]=i;
		completed[i]=1;
		for(int j=0;j<resource;j++)
		    available[j]+=allocation[i][j];
		count1++;
	    }
	    k=0;

	}

	if(count1==count2)
	{
	    flag=0;
	    break;
	}
    }
    return flag;
}


void requestAllocation()
{
    int c1=0,c2=0;

    for(int i=0;i<resource;i++)
    {
	if(request[i]<=need[requestedBy][i])
	    c1++;
	if(request[i]<=available[i])
	    c2++;
    }


    if(c1!=resource)
    {
	printf("\nERROR !!! Request cannot be greater than need !!!\n");
	return;
    }

    if(c2!=resource)
    {
	printf("\nERROR !!! Enough resources not available right now !!!\n");
	return;
    }

    for(int i=0;i<resource;i++)
    {
	available[i]-=request[i];
	allocation[requestedBy][i]+=request[i];
	need[requestedBy][i]-=request[i];
    }
    
    int check=safetyAlgorithm();
    if(check)
    {
	printf("\nRequest Granted !!!");
	printf("\nSafe Sequence:\n");
	for(int i=0;i<process;i++)
	    printf("P[%d]\t",safeSequence[i]);

    }
    else
    {
	printf("\nUnable to grant Request due to Deadlock !!!");
	for(int i=0;i<resource;i++)
	{
	    available[i]+=request[i];
	    allocation[requestedBy][i]-=request[i];
	    need[requestedBy][i]+=request[i];
	}
    }


}
void main()
{
    
	printf("Enter the number of processes:");
	scanf("%d",&process);
	printf("Enter the number of different types of resources:");
	scanf("%d",&resource);
	
	printf("\nEnter the currently available instances of :\n");
	for(int i=0;i<resource;i++)
	{
	    printf("\nResource Type %d :",i+1);
	    scanf("%d",&available[i]);
	}


	for(int i=0;i<process;i++)
	{
	    printf("\nEnter the MAX Value of resource required by process %d",i);
	    for(int j=0;j<resource;j++)
	    {
		printf("\nResource Type %d:",j+1);
		scanf("%d",&max[i][j]);
	    }
	}

	for(int i=0;i<process;i++)
	{
		printf("\nEnter the ALLOTED Value of resource to process %d",i);
		for(int j=0;j<resource;j++)
		{
		    printf("\nResource type %d:",j+1);
		    scanf("%d",&allocation[i][j]);
		    need[i][j]=max[i][j]-allocation[i][j];

		}

	}

	int choice;
	while(1)
	{

	    printf("Enter choice :\n1.Safety Algorithm\n2.Request Allocation\n3.Exit\n");
	    scanf("%d",&choice);
	    switch(choice)
	    {
		case 1: {
			   int flag=safetyAlgorithm();

			   if(flag)
			   {	    
				printf("\nSafe Sequence:\n");
				for(int i=0;i<process;i++)
				    printf("P[%d]\t",safeSequence[i]);
			   }
			   else
				printf("\nUNSAFE Sequence!!!!!\n");
			   break;
			}


		case 2:	{
			    printf("\nEnter the process which is requesting :");
			    scanf("%d",&requestedBy);
			    printf("Enter the request vector\n");
			    for(int i=0;i<resource;i++)
				scanf("%d",&request[i]);
			    requestAllocation();
			    break;
			}

		case 3: exit(0);

	    }
	
	}	


}
