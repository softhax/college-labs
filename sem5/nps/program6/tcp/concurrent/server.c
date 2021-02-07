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
    int server_socket,client_socket;
    struct sockaddr_in server_address,client_address;
    int buffer_size = 1024,recv_bytes,client_length;
    char *buffer = malloc(buffer_size);
    // Create a server socket
    if ( ( server_socket = socket(AF_INET,SOCK_STREAM,0))   < 0  )
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


    // Start listening for incoming connections
    if (listen(server_socket,3) < 0)  
    {
	perror("listen");
	exit(2);
    }
    printf("Started Listening at address %s and port %d...\n",inet_ntoa(server_address.sin_addr),htons(server_address.sin_port));

    int pid;
    while(1)
    {
	client_length = sizeof(struct sockaddr_in);
	client_socket = accept(server_socket,(struct sockaddr*)&client_address,&client_length);
	
	if( (pid = fork()) == 0)
	{
	    printf("inside child\n");
	    close(server_socket);

	    again : while( (recv_bytes = recv(client_socket,buffer,buffer_size,0)) > 0 ) 
		{
		    printf("Received from Client %s, %d : %s\n",inet_ntoa(client_address.sin_addr),ntohs(client_address.sin_port),buffer);
		    send(client_socket,buffer,recv_bytes,0);
		}

	    if(recv_bytes < 0 )
		goto again;


	    exit(0);
	}
    }
    close(client_socket);
}
