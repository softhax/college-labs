#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>


void main()
{
    int server_socket;
    struct sockaddr_in server_address,client_address;
    int buffer_size = 1024,recv_bytes,client_length;
    char *buffer = malloc(buffer_size);
    // Create a server socket
    if ( ( server_socket = socket(AF_INET,SOCK_DGRAM,0))   < 0  )
    {
	perror("socket");
	exit(0);
    }
    printf("Socket created successfully..\n");
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(15000);

    // Bind socket to the address structure
    if( bind(server_socket,(struct sockaddr *)&server_address,sizeof(server_address)) < 0)
    {
	    perror("bind");
	    exit(1);
    }
    printf("Bind Successful...\n");
    client_length = sizeof(client_address);
again : while( (recv_bytes = recvfrom(server_socket,buffer,buffer_size,0,(struct sockaddr*)&client_address,&client_length)) > 0 ) 
	{
	    printf("Received from Client %s : %s\n",inet_ntoa(client_address.sin_addr),buffer);
	    sendto(server_socket,buffer,recv_bytes,0,(struct sockaddr *)&client_address,client_length);
	}

	if(recv_bytes < 0 )
	    goto again;
    close(server_socket);
}
