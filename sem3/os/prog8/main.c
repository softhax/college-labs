#include<stdio.h>
int add(int a,int b);
void main()
{
    int a,b;
    printf("Enter 2 numbers:");
    scanf("%d%d",&a,&b);
    printf("Sum is %d",add(a,b));
}
