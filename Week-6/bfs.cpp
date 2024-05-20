#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

// Function to convert an adjacency matrix to an adjacency list
void convertToAdjList(vector<vector<int>> &adjMatrix, vector<list<int>> &adjList)
{
    int v = adjMatrix.size();
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
}

// Function to check if the graph is bipartite
bool isBipartite(vector<list<int>> &adjList, int src, int v)
{
    vector<int> color(v, -1);
    queue<int> q;

    q.push(src);
    color[src] = 0;

    while (!q.empty())
    {
        src = q.front();
        q.pop();

        for (auto neighbor : adjList[src])
        {
            if (color[neighbor] == -1)
            {
                color[neighbor] = 1 - color[src];
                q.push(neighbor);
            }
            else if (color[neighbor] == color[src])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));
    vector<list<int>> adjList(v);

    cout << "Enter the adjacency matrix (0 or 1): " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    // Convert adjacency matrix to adjacency list
    convertToAdjList(adjMatrix, adjList);

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    if (isBipartite(adjList, src, v))
    {
        cout << "The graph is Bipartite" << endl;
    }
    else
    {
        cout << "The graph is not Bipartite" << endl;
    }

    return 0;
}
