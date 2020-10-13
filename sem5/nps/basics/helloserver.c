#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h> // for perror
#include<string.h> // for bzero and strlen
#include<unistd.h> // for close
#include <arpa/inet.h> // for inet_ntoa



// Steps in brief are :=
// 1. create socket
// 2. bind socket to a port
// 3. wait for clients
// 4. once we get a client, send "Hello World" to client
// 5. close the connection

// sys/types and sys/socket for socket call
// netinet/in for sockaddr_in structure

/*
 
   Socket Function RETURN VALUE
       On  success,  a  file  descriptor  for  the new socket is returned.  On
       error, -1 is returned, and errno is set appropriately.
 * */


/*
 *  SIZES EXPLAINED HERE
 
    struct sockaddr_in {
	short int sin_family;     // Address family, AF_INET  ----> 2 bytes
	unsigned short int sin_port;     // Port number  -----> 2 bytes
	struct in_addr sin_addr;     // Internet address  -----> 2 bytes
	unsigned char sin_zero[8];     // For padding, to make it same size as struct sockaddr  ----> 8 bytes - padding, useless
}; 
    

struct sockaddr {
    unsigned short    sa_family;    // address family, AF_xxx --->2 bytes
    char              sa_data[14];  // protocol address ----> 14 bytes
};

struct in_addr {
    unsigned long s_addr;          // load with inet_pton() ----> 4bytes
};

 * */

void main()
{

   int sockfd; // will be used to store socket file descriptor
   int len;
   int cli; // we will store return value of accept ---> this will be the socket fd of client
   struct sockaddr_in server,client;
   char msg[] = "Hello to the world of socket programming!";
   int sent; // to store the number of bytes sent to client
   
   // socket function returns -1 on error and socket file descriptor on success
   if((sockfd  = socket(AF_INET,SOCK_STREAM,0)) == -1)
   {
       perror("socket:" );
       exit(-1);
   }

   // Here we specify the communication domain as IPv4
   server.sin_family = AF_INET;

   // Here we specify the 2 byte port number
   // Since we are using 2 byte int i.e. a short integer, we use host to network short to convert
   // host byte ordering to network byte ordering
   server.sin_port = htons(10120); // we use 10000 as port here

   // this makes the socket to accept connections from all the IP's on machine
   server.sin_addr.s_addr = INADDR_ANY;
   // provide zero padding
   // this is done as a hack to make the structure sizes equal
   // sockaddr has size of 16 bytes
   // but sockaddr_in has only 8 bytes of usefuly data
   bzero(&server.sin_zero,8);

   len = sizeof(struct sockaddr_in);
   if((bind(sockfd,(struct sockaddr *)&server,len)) == -1)
   {
       perror("bind");
       exit(-1);
   }

   // int listen(int sockfd, int backlog)
   // Returns 0 on success, -1 on error
   // we have set max no of pending processes in queue to 5
   if( listen(sockfd,5) == -1)
   {
       perror("listen");
       exit(-1);
   }


   while(1)
   {
       // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
       if( ( cli = accept(sockfd,(struct sockaddr *)&client,&len) ) == -1  )
       {
	    perror("accept");
	    exit(-1);
       }

       // at this point we have received the file descriptor for client in cli

       // Now we send the msg
       sent = send(cli,msg,strlen(msg),0);

       printf("Sent %d bytes to client : %s\n",sent,inet_ntoa(client.sin_addr));


       // Close connection
       close(cli);
   }
}

