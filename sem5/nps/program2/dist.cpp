#include<iostream>
using namespace std;
const int INF = 999;
int main()
{
    
    // Input
    int numberOfRouters;
    cout<<"Enter the number of routers :\n";
    cin>>numberOfRouters;
    int distanceMatrix[numberOfRouters][numberOfRouters];
    int distanceVector[numberOfRouters];
    int pathVector[numberOfRouters];

    for(int i=0;i<numberOfRouters;i++)
    {
	for(int j=0;j<numberOfRouters;j++)
	{
	    cin>>distanceMatrix[i][j];
	}
    }

    for(int sourceRouter=0;sourceRouter<numberOfRouters;sourceRouter++)
    {

	// Initialize With Default Values
	for(int i=0;i<numberOfRouters;i++)
	{
	    distanceVector[i] = INF ;
	    pathVector[i] = -1;
	}
	distanceVector[sourceRouter] = 0;


	//Initiate Bellman Ford Algorithm
	int relaxationCount = numberOfRouters - 1;
	while(relaxationCount--)
	{
	    for(int u=0;u<numberOfRouters;u++)
	    {
		for(int v=0;v<numberOfRouters;v++)
		{
		    if(distanceVector[u] + distanceMatrix[u][v] < distanceVector[v])
		    {
			distanceVector[v] = distanceVector[u] + distanceMatrix[u][v];
			pathVector[v] = u;
		    }
		}
	    }   
	}   
	// Run one more relaxation to check if there are negative weighted edges. If there is a
	// negative weighted edge present then terminate the program.
	for(int u=0;u<numberOfRouters;u++)
	{   
	    for(int v = 0;v<numberOfRouters;v++)
	    {
		if(distanceVector[u] + distanceMatrix[u][v] < distanceVector[v])
		{
		    cout<<"\nNegative Weight Cycle Present....Terminating......\n\n";
		    exit(0);
		}
	    }
	}

	//Display the result for current Source Router
	cout<<"Source Router : "<< sourceRouter<<"\n------------------------------------------\n\n";
	for(int i=0;i<numberOfRouters;i++)
	{
	    cout<<"To reach router :"<<i<<endl;
	    if(i!=sourceRouter)
	    {
		int j = i;
		while(j!=sourceRouter)
		{
		    cout<<j<<" <-- ";
		    j = pathVector[j];
		}
		cout<<sourceRouter<<endl;
	    }
	    cout<<"Cost : "<<distanceVector[i]<<endl<<endl;
	    
	}

	cout<<endl<<endl<<endl;
    }
    


    return 0;


}

