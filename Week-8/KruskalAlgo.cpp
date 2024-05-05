#include <bits/stdc++.h>

using namespace std;

class DisjointSet
{
public:
    vector<int> size, parent;
    DisjointSet(int v)
    {
        size.resize(v + 1, 0);
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

    // adjecency list for the weighted graph
    void adjList(int src, int des, int Weight)
    {
        adj[src].push_back({des, Weight});
        adj[des].push_back({src, Weight});
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
                sortedEdge.push_back({weight, {node, adjNode}});
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
    int v = 6;
    Kruskal k(v);
    k.adjList(0, 1, 1);
    k.adjList(0, 5, 3);
    k.adjList(1, 2, 4);
    k.adjList(1, 4, 5);
    k.adjList(1, 5, 2);
    k.adjList(5, 4, 6);
    k.adjList(2, 4, 7);
    k.adjList(2, 3, 8);
    k.adjList(4, 3, 9);

    int minWeight = k.kruskalAlgo(v);
    cout << "Minimum weight of the MST : " << minWeight << endl;

    return 0;
}