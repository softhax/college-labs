#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
void main(int argc,char *argv[])
{
    int client_fd,recv_bytes;
    struct sockaddr_in server_struct;

    char file_name[256];
    int bufsize  = 1024;
    char *buffer = malloc(bufsize);

    if( (client_fd = socket(AF_INET,SOCK_STREAM,0) ) < 0 )
    {
	perror("socket:");
	exit(0);
    }

    printf("Socket created successfully\n");

    server_struct.sin_family = AF_INET;
    server_struct.sin_port = htons(15001);
    inet_pton(AF_INET,argv[1],&server_struct.sin_addr);

    if( (connect(client_fd,(struct sockaddr *)&server_struct,sizeof(server_struct))) ==  0 )
    {
	printf("Connected successfully to the server %s \n",argv[1]);
    }
    printf("Connected successfully to the server %s \n",argv[1]);
    printf("Enter the filename to request from the server : \n");
    scanf(" %s",file_name);
    send(client_fd,file_name,sizeof(file_name),0);
    printf("Request accepted...Receiving file....\n\n");
    printf("The contents of the file are  : \n" );
    while( (recv_bytes = recv(client_fd,buffer,bufsize,0)) > 0)
    {
	write(1,buffer,recv_bytes);
    }

    printf("\nEOF\n");
    close(client_fd);

}
