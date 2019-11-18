#include<stdio.h>
#include "basic.h"
int  main()
{
    int a,b;
    printf("Enter 2 numbers:");
    scanf("%d%d",&a,&b);
    printf("Sum is %d",add(a,b));
    printf("\nDifference is %d\n",subtract(a,b));
    return 0;
}
