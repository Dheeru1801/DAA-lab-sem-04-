#include <bits/stdc++.h>
using namespace std;

void floydwarshalAlgo(vector<vector<int>> &adj, int v)
{
    // Replace unreachable nodes with a large value
    const int INF = INT_MAX / 2;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adj[i][j] == -1)
                adj[i][j] = INF;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    // Restore unreachable nodes with -1
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adj[i][j] == INF)
                adj[i][j] = -1;
        }
    }
}

int main()
{
    int v = 4;
    // adjecency matrix initialisation
    vector<vector<int>> adj{{0, 2, -1, -1},
                            {1, 0, 3, -1},
                            {-1, -1, 0, -1},
                            {3, 5, 4, 0}};

    // int edges;
    // for(int i=0;i<edges;i++)
    // {
    //     int source;
    //     int destination;
    //     int weight;
    //     cin>>source>>destination<<weight;
    //     adj[source][destination]=weight;
    // }

    floydwarshalAlgo(adj, v);
    for (int i = 0; i < v; i++)
    {
        for (auto a : adj[i])
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
