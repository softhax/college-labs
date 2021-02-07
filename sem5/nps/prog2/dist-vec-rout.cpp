#include <bits/stdc++.h>
using namespace std;
const int INF = 999;

int main()
{
	int numberOfRouters;
	cout << "Enter the number of routers:\n";
	cin >> numberOfRouters;

	int distMatrix[numberOfRouters][numberOfRouters]; // to store the path costs
	int distance[numberOfRouters];					  // to store the best
	int path[numberOfRouters];						  // to store path

	cout << "Enter the distance matrix :\n";
	for (int i = 0; i < numberOfRouters; i++)
		for (int j = 0; j < numberOfRouters; j++)
			cin >> distMatrix[i][j];
	
	cout<<"\n------------------------------------------------------------------------\n\n";
	for (int currentSource = 0; currentSource < numberOfRouters; currentSource++)
	{

		// now initialize distances to all other routers as INF (except the source itself which will be at distance 0)
		for (int currentRouter = 0; currentRouter < numberOfRouters; currentRouter++)
		{

			distance[currentRouter] = INF;
			path[currentRouter] = -1;
		}
		// initialize distance from currentSource to currentSource as 0;
		distance[currentSource] = 0;

		// Run Bellman Ford Algorithm with currentSource
		// For n vertices in graph, we can relax the distances at max n-1 times ie when all n-1 vertices in path are relaxed once
		int relaxationCount = numberOfRouters - 1;
		while (relaxationCount--)
		{
			for (int u = 0; u < numberOfRouters; u++)
			{
				for (int v = 0; v < numberOfRouters; v++)
				{
					if (distance[u] + distMatrix[u][v] < distance[v])
					{
						distance[v] = distance[u] + distMatrix[u][v];
						path[v] = u;
					}
				}
			}
		}


		// Run relaxation step once more for N'th time to
	        // check for negative-weight cycles
		for(int u = 0;u < numberOfRouters; u++)
		{
		    for(int v = 0;v < numberOfRouters; v++)
		    {
			if(distance[v] > distance[u] + distMatrix[u][v]){
			    cout<<"\nNegative Weight Cycle Present !!!!! Aborting....\n\n";
			    exit(0);
			    
			}
		    }
		}


		cout << "Source Router : " << currentSource << "\n--------------------\n\n";
		for (int i = 0; i < numberOfRouters; i++)
		{

			cout << "To reach router : " << i << endl;
			if (i != currentSource)
			{
				int j = i;
				while (path[j] != -1)
				{
					cout << j << " <-";
					j = path[j];
				}
				cout << currentSource << endl;
			}
		    	cout << "Cost : " << distance[i] << "\n\n";

		}

		cout<<"\n\n\n";
	}

	return 0;
}
