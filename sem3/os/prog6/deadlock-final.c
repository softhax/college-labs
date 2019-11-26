#include<stdio.h>
#include<stdio.h>

int i,j,k=0,p,r,com[10]={0},av[10],max[10][10],allot[10][10],nd[10][10],n;

void bankers()
{
	int n1=p*2,count=0;

	if(n1>0)
	    printf("The Safe sequence is : \n");
	while(n1--)
	{

		for(i=0;i<p;i++)
		{
			for(j=0;j<r;j++)
				if(nd[i][j]<=av[j])
					k++;
			if(k==r && com[i]==0)
			{
			    printf("Process - %d\n",i);
			    com[i]=1;
			    count++;
			    for(j=0;j<r;j++)
				av[j]+=allot[i][j];
			}

			k=0;
		}

		if(count==p)
		{
			printf("system is in safe sequence\n");
			break;
		}
	}
	if(n1<=0)
		printf("unsafe state\n");
}


void main()
{
	int k1,req[10],ch;	
	printf("\nEnter the no of processess:");
	scanf("%d",&p);
	printf("\nEnter the no of different resources:");
	scanf("%d",&r);

	for(i=0;i<r;i++){
		printf("\nEnter the currently available instances of resource type %d:",i+1);
		scanf("%d",&av[i]);
	}


	for(i=0;i<p;i++)
	{
		printf("\nEnter the Max Value of resource req by process %d",i);
		for(j=0;j<r;j++)
		{
		    printf("\nResource of type %d:",j+1);
		    scanf("%d",&max[i][j]);
		}
	}


	for(i=0;i<p;i++)
	{
                printf("\nEnter the Alloted  Value of resource to process %d",i);
                for(j=0;j<r;j++)
		{
		    printf("\nResource of type %d:",j+1);
		    scanf("%d",&allot[i][j]);
		    nd[i][j]=max[i][j]-allot[i][j];
                }
        }
	while(1)
	{
	    printf("\nEnter Choice : \n1.Safety\n2.Resource Allocation\n\n");
	    scanf("%d",&ch);
		switch(ch)
		{
		    case 1:
				bankers();
				break;
		    case 2:
				printf("enter the request vector\n");
				for(i=0;i<r;i++)
				    scanf("%d",&req[i]);
				printf("enter the process accesing the request\n");
				scanf("%d",&k1);
				for(j=0;j<p;j++)
				    for(k=0;k<r;k++)
					max[i][j]+=req[k];
				bankers();
				break;
		default:	return;
	    }
	}
	
}


