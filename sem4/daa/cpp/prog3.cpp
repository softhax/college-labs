#include<bits/stdc++.h>
using namespace std;

void dfs(int a[10][10],int n,int V[10],int source)
{
    int i;
    V[source]=1;    // Mark this source vertex as visited
    cout<<"Vertex "<<source<<" is visited."<<endl;
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
}


void bfs(int a[10][10],int n,int V[10],int source)
{
    int i,q[10],f=0,r=-1,nd;
    V[source]=1;    //Mark the vertex/node calling this func as visited
    cout<<"Vertex "<<source<<" is visited."<<endl;
    q[++r]=source;  //Add the source vertex to the rear of the queue
    while(f<=r)	    // Perform the task while  front<=rear ----> This will be false when queue becomes empty.
    {
	nd = q[f++];	// Node/Vertex to be deleted ----> This is ofcourse from the front of the queue
	for(i=0;i<n;i++)
	{
	    //If the node to be deleted i.e. the front of the queue is adjacent to vertex i and
	    //vertex i is not visited yet , then mark vertex i as visited and also add vertex i to
	    //the rear of the queue. We are doing this since in bfs we first check for a node and
	    //then we check for its neighbour in a predefined "proper" order like 1,2,3 or a,b,c
	    //For example say node 1 has neighbours 2 and 3 then we first mark 1 as visited and then 
	    //mark 2 and 3 visited and add them in this order to the queue i.e. 2 then 3.
	    //Then after this for loop again the while condition will be checked and since the queue
	    //is not empty it will again run for 2 and its neighbours and 3 and its neighbours
	    if(a[nd][i] == 1 && V[i]==0)    
	    {
		q[++r]=i;
		V[i]=1;
		cout<<"Vertex "<<i<<" is visted."<<endl;
	    }
	}
    }
}
int main()
{
    int n,i,j,A[10][10],V[10];
    cout<<"Enter the number of vertices : ";
    cin>>n;
    cout<<"Enter the adjacency matrix:"<<endl;
    for(i=0;i<n;i++)	for(j=0;j<n;j++)    cin>>A[i][j];
    
    // Performing DFS first
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


    //Performing BFS second
    cout<<"\n\nBy BFS Method :\n";
    for(i=0;i<n;i++)	V[i]=0;
    count = 0;
    for(i=0;i<n;i++)
    {
	if(V[i]==0)
	{
	    bfs(A,n,V,i);
	    count++;
	}
    }
 
    if(count==1)    cout<<"\nThe Graph is connected.\n";
    else
	cout<<"\nThe Graph is disconnected and the number of components is "<<count<<".\n";



    return 0;
}
