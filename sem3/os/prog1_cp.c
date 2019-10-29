#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    int fd1,fd2,n;
    char buff[20];
    if((fd1=open(argv[1],O_RDONLY))==-1)
    {
	printf("Error opening input file !!\n");
	exit(0);
    }

    if((fd2=open(argv[2],O_WRONLY|O_CREAT|O_APPEND,S_IRUSR))==-1)
    {
	printf("Error opening output file !!\n");
	exit(0);
    }

    while((n=read(fd1,buff,20))!=0)
	write(fd2,buff,n);
    close(fd1);
    close(fd2);

    return 0;

}
