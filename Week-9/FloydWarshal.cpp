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
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    // Adjacency matrix initialization
    vector<vector<int>> adj(v, vector<int>(v));

    cout << "Enter the adjacency matrix (use -1 for unreachable nodes):\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> adj[i][j];
        }
    }

    floydwarshalAlgo(adj, v);
    cout << "Shortest distances between vertices after Floyd-Warshall algorithm:\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
