#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> size, parent;
    DisjointSet(int v)
    {
        size.resize(v + 1, 1); // Each component initially has size 1
        parent.resize(v + 1);
        for (int i = 0; i <= v; i++)
            parent[i] = i;
    }

    int findUp(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUp(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int up_u = findUp(u);
        int up_v = findUp(v);
        if (up_u == up_v)
            return;
        if (size[up_u] < size[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Kruskal
{
public:
    list<pair<int, int>> *adj;
    Kruskal(int v)
    {
        adj = new list<pair<int, int>>[v];
    }

    // adjacency list for the weighted graph
    void adjList(int src, int des, int Weight)
    {
        adj[src].push_back({des, Weight});
        adj[des].push_back({src, Weight});
    }

    void convertToAdjList(vector<vector<int>> &adjMatrix, int v)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (adjMatrix[i][j] != 0)
                { // assuming 0 means no edge
                    adjList(i, j, adjMatrix[i][j]);
                }
            }
        }
    }

    int kruskalAlgo(int v)
    {
        int weight = 0;
        vector<pair<int, pair<int, int>>> sortedEdge;
        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
            {
                int node = i;
                int adjNode = it.first;
                int weight = it.second;
                if (node < adjNode)
                { // to avoid duplicate edges in undirected graph
                    sortedEdge.push_back({weight, {node, adjNode}});
                }
            }
        }
        sort(sortedEdge.begin(), sortedEdge.end());

        DisjointSet d(v);
        for (auto a : sortedEdge)
        {
            int wt = a.first;
            int u = a.second.first;
            int v = a.second.second;
            if (d.findUp(u) != d.findUp(v))
            {
                weight += wt;
                d.unionBySize(u, v);
            }
        }

        return weight;
    }
};

int main()
{
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));
    cout << "Enter the adjacency matrix (enter weights, 0 means no edge): " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    Kruskal k(v);
    k.convertToAdjList(adjMatrix, v);

    int minWeight = k.kruskalAlgo(v);
    cout << "Minimum weight of the MST: " << minWeight << endl;

    return 0;
}
