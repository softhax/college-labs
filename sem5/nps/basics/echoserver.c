#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<error.h>
#include<strings.h>
#include<unistd.h>
#include<arpa/inet.h>

#define ERROR -1
#define MAX_CLIENTS 2
#define MAX_DATA 1024

void main(int argc,char **argv)
{
    struct sockaddr_in server; // contains info like port, ip address for server
    struct sockaddr_in client; // contains all client info
    int sock; // server socket descriptor
    int new; // client socket descriptor
    int sockaddr_len = sizeof(struct sockaddr_in);
    int data_len;
    char data[MAX_DATA+1];

    if((sock = socket(AF_INET,SOCK_STREAM,0)) == ERROR)
    {
	perror("server socket:");
	exit(-1);
    }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1])); // get the port number from arguments in terminal and convert that char string to int
    server.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0 -->basically telling to listen to all interfaces
    bzero(&server.sin_zero,8);
    
    if((bind(sock,(struct sockaddr *)&server,sockaddr_len)) == ERROR)
    {
	perror("bind : ");
	exit(-1);
    }

    if((listen(sock,MAX_CLIENTS)) == ERROR)
    {
	perror("listen");
	exit(-1);
    }


    while(1)
    {
	// note that accept is a blocking call
	// we will be waiting here until we get a client
	// also here socket file desc is used to specify the socket we are listening to
	// new socket descriptor is the descriptor for current client
	if( ( new = accept(sock,(struct sockaddr *)&client,&sockaddr_len)) == ERROR)
	{
	    perror("accept");
	    exit(-1);
	}

	printf("New cleint connected from port no %d and IP %s\n",ntohs(client.sin_port),inet_ntoa(client.sin_addr));
	data_len = 1; 

	while(data_len>0)
	{
	    data_len = recv(new,data,MAX_DATA,0);
	    if(data_len>0)
	    {
		// 0 here specifies not defining any flags
		send(new,data,data_len,0);
		data[data_len] = '\0';
		printf("Sent msg : %s\n",data);
	    }	    
	}

	printf("Client Disconnected !! \n");
	close(new);
	
    }
}
