#include<stdio.h>
#include<stdlib.h>

//A -> Allocation
//M -> Max
//W -> Available resources
//N -> Need
//n ->number of processes
//m -> number of resources

//prints the safe sequence if it exists - else prints that the state is unsafe
int banker(int A[][10],int N[][10],int W[1][10],int n,int m);
//when resources get deallocated, checks if any of the pending requests can be granted
void deallocation (int A[10][10],int N[10][10],int AV[10][10],int pid,int n,int m);
//this function prints an n*m 2d array
void print(int x[][10],int n,int m);
//Resource Request algorithm
int res_request(int A[10][10],int N[10][10],int AV[10][10],int pid,int n,int m);
//Safe state testing algorithm
int safety(int A[][10],int N[][10],int AV[1][10],int n,int m,int a[]);
//to accept the values of the initial matrices
void accept(int A[][10],int N[][10],int M[10][10],int W[1][10],int *n,int *m);

/*global variable*/
int reqmat[10][10];//prevents the need of initialization function

int main()
{
	int A[10][10];
	int M[10][10];
	int N[10][10];
	int W[1][10];
	int pid,ch;
	int i,m,n;
	printf("\n DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM\n");
	accept(A,N,M,W,&n,&m);//initial conditions
	if (!banker(A,N,W,n,m))
        exit(0);//if the initial state itself is unsafe
	while (1)
	{
		printf("\n<Anything else> Display\n 1.Additional request\n 2.Release resource\n 3.Exit :");
		scanf("%d",&ch);
		switch (ch){
		case 1:
		{
			printf("\n Enter process no. : ");
			scanf("%d",&pid);
			printf("\n Enter additional request :- \n");
			for(i=0;i<m;i++){
				printf(" Request for resource %d : ",i+1);
				scanf("%d",&ch);
				reqmat[pid-1][i]+= ch;
			}
			res_request(A,N,W,pid-1,n,m);

			break;
		}
		case 2:
		{
			printf("\n Enter process no. : ");
			scanf("%d",&pid);
			printf("\n Enter deallocation :- \n");
			deallocation(A,N,W,pid-1,n,m);
			break;
		}
		case 3:
			exit(0);
		default:
			printf("\n Allocation Matrix");
			print(A,n,m);
			printf("\n Maximum Requirement Matrix");
			print(M,n,m);
			printf("\n Need Matrix");
			print(N,n,m);
			printf ("\n Request matrix");
			print (reqmat,n,m);
			printf ("\n Available resources:");
			print(W,1,m);
	}
	}

	return 0;
}
//fdeallocation
void deallocation (int A[10][10],int N[10][10],int AV[10][10],int pid,int n,int m)
{
	int deallocation[10];
	int i,j,flag = 1;
	int ch = 0;
	for(i=0;i<m;i++){
		printf(" Deallocation of resource %d : ",i+1);
		scanf("%d",&deallocation[i]);
	}

	for(i=0;i<m;i++)
		if(deallocation[i] > A[pid][i])
		{//if deallocated is more than allocated
			printf("\n Error encountered.\n");
			exit(0);
		}
	for (int i =0;i<m;i++)
	{
		A[pid][i] -= deallocation[i];
		N[pid][i] += deallocation[i];
		AV[0][i]+= deallocation[i];
	}//resources deallocated
	//check for possible allocations
	while (flag)
	{
		flag = 0;
	for (i  =0;i<n;i++)
	{
		ch =0;
		for (j =0;j<m;j++)
		{
			if (reqmat[i][j]!=0)
			{
				ch = res_request(A,N,AV,i,n,m);//if ch =0 not allocated
				break;
			}
		}
		if (ch)
		{
			//if allocation has occurred
			flag = 1;
		}
	}
	}

}
//fprint
void print(int x[][10],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
    {
		printf("\n");
		for(j=0;j<m;j++){
			printf("%d\t",x[i][j]);
		}
	}
}
//fres_request
int res_request(int A[10][10],int N[10][10],int AV[10][10],int pid,int n,int m)
{
	int i;

	for(i=0;i<m;i++)
		if(reqmat[pid][i] > N[pid][i])
	{//if request is more than need
			printf("\n Error encountered.\n");
			exit(0);
	}

	for(i=0;i<m;i++)
		if(reqmat[pid][i] > AV[0][i])
		{//request is more than the number of resources available
			printf("\n Resources unavailable.\n");
			return 0;
		}

	for(i=0;i<m;i++)
	{
		AV[0][i]-=reqmat[pid][i];
		A[pid][i]+=reqmat[pid][i];
		N[pid][i]-=reqmat[pid][i];
	}//after getting the request
	printf ("Simulation!!\n");
	i = banker(A,N,AV,n,m);
	if (i==0)
	{
		//if a deadlock has occurred
		for(i=0;i<m;i++)
		{
			AV[0][i]+=reqmat[pid][i];
			A[pid][i]-=reqmat[pid][i];
			N[pid][i]+=reqmat[pid][i];
		}
		return 0;
	}
	else
	{
		//request granted
		for(i=0;i<m;i++)
			reqmat[pid][i] = 0;
		return 1;
	}
}
//fsafety
int safety(int A[][10],int N[][10],int AV[1][10],int n,int m,int a[])
{

	int i,j,k,x=0;
	int F[10],W[1][10];
	int pflag=0,flag=0;
	for(i=0;i<n;i++)
		F[i]=0;//initially, none of the processes have terminated
	for(i=0;i<m;i++)
		W[0][i]=AV[0][i];//working array

	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(F[i] == 0){
				flag=0;
				for(j=0;j<m;j++)
                {
					if(N[i][j] > W[0][j])
						flag=1;
				}
				if(flag == 0 && F[i] == 0)
				{
					for(j=0;j<m;j++)
						W[0][j]+=A[i][j];
					F[i]=1;
					pflag++;
					a[x++]=i;
				}
			}
		}
		if(pflag == n)
			return 1;
	}
	return 0;
}
//faccept
void accept(int A[][10],int N[][10],int M[10][10],int W[1][10],int *n,int *m)
{
	int i,j;
	printf("\n Enter total no. of processes : ");
	scanf("%d",n);
	printf("\n Enter total no. of resources : ");
	scanf("%d",m);
	printf ("\nEnter Maximum resource matrix:\n");
	for (i = 0;i<*n;i++)
	{
		for (j = 0;j<*m;j++)
			scanf ("%d",&M[i][j]);
	}
	printf ("\nEnter Resource allocation Matrix:\n");
	for (i = 0;i<*n;i++)
	{
		for (j = 0;j<*m;j++)
			scanf ("%d",&A[i][j]);
	}
	printf("\n Available resources : \n");
	for(i=0;i<*m;i++)
    {
		printf(" Resource %d : ",i+1);
		scanf("%d",&W[0][i]);
	}

	for(i=0;i<*n;i++)
		for(j=0;j<*m;j++)
			N[i][j]=M[i][j]-A[i][j];

	printf("\n Allocation Matrix");
	print(A,*n,*m);
	printf("\n Maximum Requirement Matrix");
	print(M,*n,*m);
	printf("\n Need Matrix");
	print(N,*n,*m);
}
//fbanker
int banker(int A[][10],int N[][10],int W[1][10],int n,int m){
	int j,i,a[10];//a is to store the safety sequence
	j=safety(A,N,W,n,m,a);
	if(j != 0 )
    {
		printf("\n\n");
		for(i=0;i<n;i++)
		     printf(" P%d  ",a[i]);
		printf("\n A safety sequence has been detected.\n");
		return 1;
	}
	else
	{
		printf("\n Unsafe State.\n");
		return 0;
	}
}
