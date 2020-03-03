#include<bits/stdc++.h>
using namespace std;

bool can_be_placed(int row,int column)
{
    for(int j=1;j<=row-1;j++)
    {	
	if(x[j] = column || abs(j-row))
		return false;
    }
    return true;
}
void n_queens(int n,int k)
{
    for(int i=1;i<=n;i++)
    {
	if(can_be_placed(k,i))
	{
	   x[j] = i;
	   if(k==n)
	       write(x,1,n);
	   else
	       n_queens(k+1,n);
	}   
    }
}

int main()
{

    int n,k;
    cin>>n>>k;
    nqueens(n,k); 

    return 0;
}
