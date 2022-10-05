
#include <iostream>
using namespace std;

#define V 7

int minimumKey(int key[], bool mst[])
{
	int min = INT_MAX, minimum_index;

	for (int v = 0; v < V; v++)
	{
		if (mst[v] == false && key[v] < min)
		{
			min = key[v], minimum_index = v;
		}
	}
	return minimum_index;
}

void print(int parent[], int graph[V][V])
{
	int sum = 0;
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
	{
		cout << parent[i] + 1 << " - " << i + 1 << "     " << graph[i][parent[i]] << " \n";
		sum += graph[i][parent[i]];
	}
	cout << "\n--------------------------------" << endl;
	cout <<"\nWeight: " << sum << endl;

}


void prim(int graph[V][V])
{
	int parent[V];

	int key[V];

	bool mst[V];

	for (int i = 0; i < V; i++)
	{
		key[i] = INT_MAX, mst[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
	{
		int u = minimumKey(key, mst);

		mst[u] = true;

		for (int v = 0; v < V; v++)
		{
			if (graph[u][v] && mst[v] == false && graph[u][v] < key[v])
			{
				parent[v] = u, key[v] = graph[u][v];
			}
		}
	}

	print(parent, graph);
}

int main()
{

	int graph[V][V] = { { 0, 2, 4, 1, 0,0,0 },
						{ 2, 0, 0, 3, 10,0,0 },
						{ 4, 0, 0, 2, 0,5,0 },
						{ 1, 3, 2, 0, 7,8,4 },
						{ 0, 10, 0, 7, 0,0,6 },
						{ 0, 0, 5, 8, 0,0,1 },
						{ 0, 0, 0, 4, 6,1,0 }
	};

	prim(graph);

	return 0;
}

