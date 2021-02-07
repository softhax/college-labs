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
    if((client_socket = socket(AF_INET,SOCK_DGRAM,0))<0)
    {
	perror("socket");
	exit(0);

    }

    printf("Successfully created socket..\n");

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(15000);
    inet_pton(AF_INET,argv[1],&server_address.sin_addr);
    int server_length = sizeof(server_address);

    while(fgets(buffer,buffer_size,stdin) != NULL)
    {
	sendto(client_socket,buffer,buffer_size,0,(struct sockaddr*)&server_address,server_length);
	
    
	if( (recv_bytes = recvfrom(client_socket,buffer,buffer_size,0,(struct sockaddr*)&server_address,&server_length))  > 0  )
	{
	    printf("Reply from Server : %s\n",buffer);
	}
	
    }

    printf("\nEOF\n");

    close(client_socket);
    
}
