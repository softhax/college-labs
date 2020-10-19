#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
    char hname[256];
    char *IPaddr;
    struct hostent *hptr;
    int hostname;
    struct in_addr addr;

    // Retrieve hostname
    hostname = gethostname(hname,sizeof(hname));

    // Retrieve host info
    if((hptr = gethostbyname("www.gmail.com")) == NULL)
    {
	printf("error");
	exit(0);
    }

    // to convert an internet network address into ascii string
    IPaddr = inet_ntoa(*((struct in_addr*)hptr->h_addr_list[0]));

    // contents of hostent structure
    printf("HOST IP : %s\n",IPaddr);
    printf("Hostname : %s\n",hptr->h_name);
    printf("Hostname Alias 0 : %s\n",hptr->h_aliases[0]);
    printf("Hostname Alias 1 : %s\n",hptr->h_aliases[1]);
    printf("Address Type : %d\n",hptr->h_addrtype);
    printf("Address Length : %d\n",hptr->h_length);
    
    printf("\n\nNow demonstrating gethostbyaddress:\n");
   // inet_aton("172.217.163.36",&addr);
    inet_aton("192.168.122.1",&addr);
    hptr = gethostbyaddr(&addr,sizeof(addr),AF_INET);
    printf("Host name : %s\n",hptr->h_name);

    return 0;
}
