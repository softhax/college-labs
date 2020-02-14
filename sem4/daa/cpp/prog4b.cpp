#include<bits/stdc++.h>
using namespace std;

int topo[10] = {0};
int numberOfNodes;
void dfs(int a[10][10],int n,int V[10],int source)
{
    int i;
    V[source]=1;    // Mark this source vertex as visited
    for(i=0;i<n;i++)
    {
	// If source is adjacent to i and i is not visited yet then call dfs on i
	// Doing this will mark i has visited and do dfs further
	// Thus recursively nodes would get marked until end is reached where all adjacent vertices
	// are already visited.
	if(a[source][i]==1 && V[i]==0)
	{
	    dfs(a,n,V,i);
	}
    }
    topo[numberOfNodes--]=source;
}

int main()
{
    int n,i,j,A[10][10],V[10];
    cout<<"Enter the number of vertices : ";
    cin>>n;
    numberOfNodes = n-1 ;
    cout<<"Enter the adjacency matrix:"<<endl;
    for(i=0;i<n;i++)	for(j=0;j<n;j++)    cin>>A[i][j];
    
    // Performing DFS Method for traversal and topological ordering
    cout<<"\n\nBy DFS Method : \n";
    for(i=0;i<10;i++)	V[i]=0;//Marking all the vertices by 0 which means not visited (yet).
    int count = 0;	//Initializing the number of components as 0

    for(i=0;i<n;i++)
    {
	if(V[i]==0)
	{
	    dfs(A,n,V,i);
	    count++;
	}
    }
    
    if(count==1)    cout<<"\nThe Graph is connected.\n";
    else
	cout<<"\nThe Graph is disconnected and the number of components is "<<count<<".\n";
    cout<<"\nThe topological ordering is :"<<endl;
    for(i=0;i<n;i++)	cout<<topo[i]<<" ";
    cout<<endl;
    return 0;
}
