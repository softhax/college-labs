#include<stdio.h>

int fact(int num)
{
    return ((num==0 || num==1) ? 1 : num*fact(num-1));
}

int main()
{
    int n;
    printf("Enter the number to calculate factorial : ");
    scanf("%d",&n);
    printf("\nThe Factorial of %d is : %d\n",n,fact(n));
    return 0;
}
