#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{

    if(unlink(argv[1])==0)
	printf("\nFile Deleted Sucessfully !!\n");
    else
	printf("\nError !! Deletion Unsucessful !");
    return 0;

}
