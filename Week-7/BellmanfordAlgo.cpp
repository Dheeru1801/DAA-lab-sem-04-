#include <bits/stdc++.h>
using namespace std;

// Function to convert an adjacency matrix to an adjacency list with weights
void convertToAdjList(vector<vector<int>> &adjMatrix, vector<list<pair<int, int>>> &adjList)
{
    int v = adjMatrix.size();
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adjMatrix[i][j] != 0)
            { // assuming 0 means no edge
                adjList[i].push_back({j, adjMatrix[i][j]});
            }
        }
    }
}

// Function to convert an adjacency list to an edge list
void createEdge(vector<list<pair<int, int>>> &adjList, vector<vector<int>> &edge, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (auto a : adjList[i])
        {
            int node = i;
            int adjNode = a.first;
            int weight = a.second;
            edge.push_back({node, adjNode, weight});
        }
    }
}

// Bellman-Ford algorithm
vector<int> bellmanFordAlgo(vector<vector<int>> &edge, int src, int v, vector<int> &parent)
{
    vector<int> dis(v, INT_MAX);
    dis[src] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        for (auto it : edge)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dis[u] != INT_MAX && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                parent[v] = u;
            }
        }
    }

    // Nth relaxation to check for the negative cycle
    for (auto it : edge)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if (dis[u] != INT_MAX && dis[u] + w < dis[v])
        {
            cout << "Negative edge cycle found" << endl;
            return {-1};
        }
    }

    return dis;
}

// Function to print the path using the parent vector
void printPath(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        cout << node;
        return;
    }
    printPath(parent, parent[node]);
    cout << " -> " << node;
}

int main()
{
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));
    vector<list<pair<int, int>>> adjList(v);

    cout << "Enter the adjacency matrix (enter weights, 0 means no edge): " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    // Convert adjacency matrix to adjacency list
    convertToAdjList(adjMatrix, adjList);

    vector<vector<int>> edge;
    createEdge(adjList, edge, v);

    vector<int> parent(v);
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    vector<int> dis = bellmanFordAlgo(edge, 0, v, parent);

    if (dis[0] != -1)
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Path to " << i << ": ";
            printPath(parent, i);
            cout << " - Distance: " << dis[i] << endl;
        }
    }

    return 0;
}
