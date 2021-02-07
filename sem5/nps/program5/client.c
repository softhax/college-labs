#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

void main(int argc,char *argv[])
{
    int client_socket,recv_bytes;
    struct sockaddr_in server_address;
    int buffer_size = 1024;
    char *buffer = malloc(buffer_size);
    if((client_socket = socket(AF_INET,SOCK_STREAM,0))<0)
    {
	perror("socket");
	exit(0);

    }

    printf("Successfully created socket..\n");

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(15000);
    inet_pton(AF_INET,argv[1],&server_address.sin_addr);

    if(connect(client_socket,(struct sockaddr*)&server_address,sizeof(server_address)) < 0)
    {
	perror("connect");
	exit(1);
    }
    printf("Connection made successfully...\n");
    
    printf("Client:");
    while(fgets(buffer,buffer_size,stdin) != NULL)
    {
	send(client_socket,buffer,buffer_size,0);
	
    
	if( (recv_bytes = recv(client_socket,buffer,buffer_size,0))  > 0  )
	{
	    printf("Server : %s\n",buffer);
	}
	
	printf("Client:");
    }

    printf("\nEOF\n");

    close(client_socket);
    
}
