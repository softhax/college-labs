#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>


int main()
{
    struct servent* se;
    se = getservbyname("domain","udp");
    printf("%d\n",htons(se->s_port));

    se = getservbyname("ftp","tcp");
    printf("%d\n",htons(se->s_port));

    se = getservbyname("http","tcp");
    printf("%d\n",htons(se->s_port));

    se = getservbyname("telnet","tcp");
    printf("%d\n",htons(se->s_port));

    se = getservbyname("https","tcp");
    printf("%d\n",htons(se->s_port));

    se = getservbyname("daytime","tcp");
    printf("%d\n",htons(se->s_port));


    printf("Getserverbyport function output\n");
    
    se = getservbyport(htons(53),"udp");
    printf("%s\n",se->s_name);

    se = getservbyport(htons(21),"tcp");
    printf("%s\n",se->s_name);


    se = getservbyport(htons(80),"tcp");
    printf("%s\n",se->s_name);

    se = getservbyport(htons(23),"tcp");
    printf("%s\n",se->s_name);

    se = getservbyport(htons(443),"tcp");
    printf("%s\n",se->s_name);

    se = getservbyport(htons(13),"udp");
    printf("%s\n",se->s_name);


}
