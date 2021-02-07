#include<stdio.h>
unsigned int fields[10];
unsigned short checksum(){
    int sum = 0;
    printf("Enter IP header information in 16 bit words\n");
    for(int i=0;i<9;i++)
    {
	printf("Field %d\n",i+1);
	scanf("%x",&fields[i]);
	sum = sum + (unsigned short) fields[i];

	while(sum>>16)
	    sum = (sum & 0xFFFF)
    }
}

void main()
{
    int a = checksum();
    int b = checksum();


    if(a == b)
	printf("Identical Checksum.....Information Correct !!!!!");
    else
	printf("labs

    
}
