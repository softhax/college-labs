#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

void main()
{
    struct sockaddr_in server_struct,client_struct;
    int server_fd,client_fd,client_len,file_fd,read_bytes;
    char file_name[256];
    int bufsize = 1024;
    char *buffer = malloc(bufsize);

    // Create a a socket
    if( (server_fd = socket(AF_INET,SOCK_STREAM,0)) < 0 ) 
    {
	perror("socket");
	exit(0);
    }
    printf("Successfully Created Socket...\n");


    // Fill structure
    server_struct.sin_family = AF_INET;
    server_struct.sin_addr.s_addr = INADDR_ANY;
    server_struct.sin_port = htons(15001);
    bzero(&server_struct.sin_addr,8);
    // Bind socket
    if ( bind(server_fd,(struct sockaddr *)&server_struct,sizeof(server_struct)) < 0 ) 
    {
	perror("bind");
	exit(1);
	
    }
    printf("Successfully binded socket...\n");


    // Start listening
    if(listen(server_fd,3)  < 0 )
    {
    
	perror("listen:");
	exit(2);
    }
    printf("Listening at port 15001....\n\n");

    
    // Accept an incoming client request.
    client_len = sizeof(struct sockaddr_in);
    client_fd = accept(server_fd,(struct sockaddr *)&client_struct,&client_len);
    if(client_fd > 0 )
    {
	printf("The client %s has connected...\n",inet_ntoa(client_struct.sin_addr));
	
    }

    // Receive file name
    recv(client_fd,file_name,255,0);
    printf("A request for filename %s is received.\n",file_name);
    
    // Open file
    if ((file_fd = open(file_name,O_RDONLY)) < 0  )
    {
	perror("file open failed:");
	exit(3);
    }

    // Read contents of the file and send them

    while( ( read_bytes = read (file_fd,buffer,bufsize) ) > 0  )
    {
	
	send(client_fd,buffer,read_bytes,0);
    }
    printf("Request Completed !! \n\n");


    close(client_fd);
    close(server_fd);
}
