/*The addrinfo structure used by getaddrinfo() contains the following
       fields:

           struct addrinfo {
               int              ai_flags;
               int              ai_family;
               int              ai_socktype;
               int              ai_protocol;
               socklen_t        ai_addrlen;
               struct sockaddr *ai_addr;
               char            *ai_canonname;
               struct addrinfo *ai_next;
           };

       The hints argument points to an addrinfo structure that specifies
       criteria for selecting the socket address structures returned in the
       list pointed to by res.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{

  struct addrinfo hints, *res;
  int errcode;
  char addrstr[100];
  void *ptr;

  memset (&hints, 0, sizeof (hints));
 // hints.ai_family = AF_UNSPEC;
  hints.ai_family = AF_INET;
  //hints.ai_family = AF_INET6;
  hints.ai_socktype = SOCK_DGRAM;
  //hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags |= AI_CANONNAME;
 
  

  errcode = getaddrinfo("netflix.com", NULL, &hints, &res);
	
  if (errcode != 0)
    {
      //perror ("getaddrinfo");
      //return -1;
	printf("error code%d",errcode);
    }

  printf ("Host: %s\n", "www.netflix.com");
  while (res)
    {
      inet_ntop (res->ai_family, res->ai_addr->sa_data, addrstr, 100);

      switch (res->ai_family)
        {
        case AF_INET:
          ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
          break;
        case AF_INET6:
          ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
          break;
        }
      inet_ntop (res->ai_family, ptr, addrstr, 100);
      printf ("IPv%d address: %s (%s)\n", res->ai_family == PF_INET6 ? 6 : 4,
              addrstr, res->ai_canonname);
      res = res->ai_next;
    }

  return 0;
}
