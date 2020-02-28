#include<bits/stdc++.h>
using namespace std;

int main()
{
    //n is the numebr of items
    //w is the total weight
    int n,w;
    cin>>n>>w;
    int weight[n+1],value[n+1];
    for(int i=1;i<=n;i++)
	cin>>weight[i]>>value[i];
    int dp_mat[n+1][w+1]={};
    for(int i=0;i<=n;i++)
    {
	for(int j=0;j<=w;j++)
	{
	    if(i==0 || j==0)
		dp_mat[i][j]=0;
	    else if(weight[i]<=j)
		dp_mat[i][j] = max(dp_mat[i-1][j],value[i] + dp_mat[i-1][j-weight[i]]);
	    else
		dp_mat[i][j] = dp_mat[i-1][j];
	}
    }

    cout<<dp_mat[n][w];
    return 0;
}
