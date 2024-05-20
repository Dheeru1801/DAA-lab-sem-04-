#include <iostream>
#include <vector>
#include <list>

using namespace std;

// A utility function to add an edge in a directed graph.
void addEdge(vector<list<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

// A utility function to perform DFS traversal
void DFS(const vector<list<int>> &adj, int v, vector<bool> &visited)
{
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    for (int neighbor : adj[v])
    {
        if (!visited[neighbor])
        {
            DFS(adj, neighbor, visited);
        }
    }
}

// Function to find a mother vertex in the given directed graph
int findMotherVertex(const vector<list<int>> &adj, int V)
{
    vector<bool> visited(V, false);
    int lastFinishedVertex = 0;

    // Perform DFS for all vertices to find the last finished vertex
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            DFS(adj, i, visited);
            lastFinishedVertex = i;
        }
    }

    // Reset visited array and perform DFS from last finished vertex
    fill(visited.begin(), visited.end(), false);
    DFS(adj, lastFinishedVertex, visited);

    // Check if all vertices are visited
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            return -1; // No mother vertex found
        }
    }

    return lastFinishedVertex;
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adjMatrix(V, vector<int>(V));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> adjMatrix[i][j];
        }
    }

    vector<list<int>> adj(V);
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (adjMatrix[i][j] == 1)
            {
                addEdge(adj, i, j);
            }
        }
    }

    int motherVertex = findMotherVertex(adj, V);

    if (motherVertex == -1)
    {
        cout << "No mother vertex found." << endl;
    }
    else
    {
        cout << "The mother vertex is: " << motherVertex << endl;
    }

    return 0;
}
