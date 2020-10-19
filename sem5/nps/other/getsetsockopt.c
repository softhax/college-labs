#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<netinet/tcp.h>

int main()
{
	int sockfd;
	int len;
	int t1,t2;
	int i;
	//create a socket first	
	sockfd= socket(AF_INET, SOCK_STREAM,0);
	
	i= sizeof(len);
	if(getsockopt(sockfd,SOL_SOCKET,SO_SNDBUF, &len,&i)<0)
		printf("error#n");
	printf("receive buffer size:%d\n",len);	

	i= sizeof(len);
	if(getsockopt(sockfd,IPPROTO_TCP,TCP_MAXSEG, &len,&i)<0)
		printf("error#n");
	printf("TCP MAX SEG SIZE size:%d\n",len);

	i= sizeof(len);
	if(getsockopt(sockfd,IPPROTO_IP,IP_TTL, &len,&i)<0)
		printf("error#n");
	printf("IP TTL :%d\n",len);
	
	t1=10000;
	t2=sizeof(int);
	if(setsockopt(sockfd,SOL_SOCKET,SO_RCVBUF, &t1,t2)<0)
		printf("error#n");
	
	i= sizeof(len);
	if(getsockopt(sockfd,SOL_SOCKET,SO_RCVBUF, &len,&i)<0)
		printf("error#n");
	printf("mdified receive buffer size:%d\n",len);	
	
}
