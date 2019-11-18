#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
    int fd;
    fd=fork();

    if(fd==0)
    {
	printf("Child Process id %d",getpid());
	fflush(stdout);
	execl("./fact","fact.c",argv[1],NULL);
    }
    else
    {
	wait(NULL);
	printf("Parent process id %d",getpid());
	fflush(stdout);
	execl("./permute","permute.c",argv[2],NULL);
    }
    return 0;
}
