#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>> &edges, int u, int v, int w)
{ // function to add edge into the matrix
    edges.push_back({u, v, w});
}

// implementing adjecency list
void adjList(list<pair<int, int>> adj[], vector<vector<int>> edges)
{
    int n = edges.size();
    for (auto a : edges)
    {
        int src = a[0];
        int des = a[1];
        int weight = a[2];
        adj[src].push_back({des, weight});
        adj[des].push_back({src, weight});
    }
}
//for max profit
int prims(vector<vector<int>> edges, int n, int start)
{
    int weight = 0;
    list<pair<int, int>> adj[n];
    adjList(adj, edges);

    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    vector<int> visited(n, 0);

    //{weight,node}
    pq.push({0, start});
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int w = it.first;
        int node = it.second;

        if (visited[node] == 1)
            continue;

        visited[node] = 1;
        weight += w;
        for (auto a : adj[node])
        {
            int adjNode = a.first;
            int wt = a.second;
            if (visited[adjNode] != 1)
            {
                pq.push({wt, adjNode});
            }
        }
    }

    return weight;
}

int main()
{
    int v = 6;
    vector<vector<int>> edges;

    list<pair<int, int>> adj[v];

    addEdge(edges, 0, 1, 6);
    addEdge(edges, 0, 5, 4);
    addEdge(edges, 1, 5, 5);
    addEdge(edges, 1, 2, 7);
    addEdge(edges, 1, 4, 1);
    addEdge(edges, 5, 4, 2);
    addEdge(edges, 2, 4, 9);
    addEdge(edges, 3, 2, 8);
    addEdge(edges, 4, 3, 3);

    adjList(adj, edges);
    // printEdges(edges);
    // printAdjList(adj,v);

    int minWeight = prims(edges, v, 0);
    cout << "minimum weight for the mst is : " << minWeight << endl;

    return 0;
}
