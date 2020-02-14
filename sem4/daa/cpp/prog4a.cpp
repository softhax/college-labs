#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,k,indegree[10]={0},top=-1,stack[10]={0},nd,result[10]={0},a[10][10]={0},visited[10]={0};
    cout<<"Enter the number of vertices : ";
    cin>>n;
    cout<<"Enter the adjacency matrix:"<<endl;
    for(i=0;i<n;i++)
    {
	for(j=0;j<n;j++)
	{
	    cin>>a[i][j];
	    if(a[i][j]==1)  indegree[j]++;
	}
    }
    
    // Performing Vertex Deletion Method for traversal and topological ordering
    cout<<"\n\nBy Vertex Deletion / Source Removal  Method : \n";
    for(i=0;i<n;i++)
    {
	if(indegree[i]==0)
	    stack[++top]=i;
    }
    
    while(top!=-1)
    {
	nd = stack[top--];
	result[k++] = nd;
	visited[nd]=1;
	for(i=0;i<n;i++)
	    if(a[nd][i]==1)
		indegree[i]--;
	for(i=0;i<n;i++)
	    if(indegree[i]==0 && visited[i]==0)
		stack[++top] = i;

    }
    
    cout<<"\nThe topological ordering is :"<<endl;
    for(i=0;i<n;i++)	cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
