#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>

void main(int argc,char *argv[])
{
    int client_fd;
    struct sockaddr_in server_address;

    char command_name[50];

    if( ( client_fd = socket(AF_INET,SOCK_STREAM,0) ) < 0 )
    {
		
	perror("socket");
	exit(0);
    }

    printf("Socket created succsessfuly...\n");


    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(15001);
    inet_pton(AF_INET,argv[1],&server_address.sin_addr);
    
    if( connect(client_fd,(struct sockaddr *)&server_address,sizeof(server_address)) !=  0)
    {
	perror("connect");
	exit(1);
    }

    printf("Connection Successful.....\n");
    while(1)
    {
	printf("Enter the command :");
	scanf("%s",command_name);
	if(strcmp(command_name,"exit") == 0)
	{
	    send(client_fd,command_name,50,0);
	    close(client_fd);
	    break;
	}
	else
	{
	    send(client_fd,command_name,50,0);
	}
	
    }

}
