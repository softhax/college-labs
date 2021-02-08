#include<stdio.h>

void main()
{
    int sentCode[7],receivedCode[7];
    printf("Enter 4 bits of data one by one :\n");
    scanf("%d",&sentCode[0]); // d3
    scanf("%d",&sentCode[1]); // d2 
    scanf("%d",&sentCode[2]); // d1
    scanf("%d",&sentCode[3]); // d0

    // calculation of redundant bits
    sentCode[4]=(sentCode[2] + sentCode[1] + sentCode[0])%2; //r2 = d1 + d2 + d3 % 2 
    sentCode[5]=(sentCode[3] + sentCode[1] + sentCode[0])%2; //r1 = d0 + d2 + d3 % 2
    sentCode[6]=(sentCode[3] + sentCode[2] + sentCode[0])%2; //r0 = d0 + d1 + d3 % 2
    
    printf("Encoded Data : \n");
    for(int i=0;i<7;i++)
    	printf("%d ",sentCode[i]);
    
    printf("Enter received data bits one by one: \n");
    for(int i=0;i<7;i++)
    	scanf("%d",&receivedCode[i]);
    int c,s0,s1,s2;
    s2=(receivedCode[2] + receivedCode[1] + receivedCode[0] + receivedCode[4])%2; //s2 = d1 + d2 + d3 + r2 % 2 
    s1=(receivedCode[3] + receivedCode[1] + receivedCode[0] + receivedCode[5])%2; //s1 = d0 + d2 + d3 +r1 % 2
    s0=(receivedCode[3] + receivedCode[2] + receivedCode[0] + receivedCode[6])%2; //s0 = d0 + d1 + d3 +r0 % 2
    c = (s2*4) + (s1*2) + s0;

    printf("Syndrome bits are :\ns2:%d\ns1:%d\ns0:%d\n",s2,s1,s0);

    if( c== 0)
	printf("No error while transmitting data !!!\n\n");
    else
    {
	printf("Error on position %d\n",c);
	printf("Corrected Message is : \n");

	//r0
	if(s2 == 0 && s1 == 0 && s0 == 1)
	    receivedCode[6] = 1 - receivedCode[6];

	// r1
	else if(s2 == 0 && s1 == 1 && s0 == 0)
	    receivedCode[5] = 1 -receivedCode[5];

	//d0
	else if(s2 == 0 && s1 == 1 && s0 == 1)
	    receivedCode[3] = 1 -receivedCode[3];

	//r2
	else if(s2 == 1 && s1 == 0 && s0 == 0)
	    receivedCode[4] = 1 -receivedCode[4];

	//d1
	else if(s2 == 1 && s1 == 0 && s0 == 1)
	    receivedCode[2] = 1 -receivedCode[2];

	//d2
	else if(s2 == 1 && s1 == 1 && s0 == 0)
	    receivedCode[1] = 1 -receivedCode[1];

	//d3
	else if(s2 == 1 && s1 == 1 && s0 == 1)
	    receivedCode[0] = 1 -receivedCode[0];

	for(int i=0;i<7;i++)
	    printf("%d ",receivedCode[i]);
    }
}




