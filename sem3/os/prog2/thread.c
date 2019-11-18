#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

void *fact(void* x)
{
    int num=atoi(x);
	int ans=1;
	for(int i=2;i<=num;i++)
	    ans*=i;
	printf("\nThe factorial of %d is %d\n",num,ans);
	pthread_exit(0);
}
void *square(void* x)
{
    int num=atoi(x);
	printf("\nThe square of %d is : %d\n",num,num*num);
	pthread_exit(0);
}
int main(int argc,char* argv[])
{
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,square,argv[1]);
	pthread_create(&thread2,NULL,fact,argv[1]);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}
