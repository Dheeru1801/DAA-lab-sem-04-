#include <iostream>
#include <vector>
#include <list>
#include <stack>

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

// Function to find and print path between source and destination using DFS
bool dfs(vector<list<int>> &adjList, int src, int dest, vector<int> &visited, vector<int> &path)
{
    stack<int> s;
    s.push(src);
    visited[src] = 1;

    while (!s.empty())
    {
        src = s.top();
        path.push_back(src);
        s.pop();

        if (src == dest)
            return true;

        for (auto a : adjList[src])
        {
            if (visited[a] != 1)
            {
                visited[a] = 1;
                if (dfs(adjList, a, dest, visited, path))
                    return true;
                else
                    path.pop_back();
            }
        }
    }

    return false;
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

    int src, dest;
    cout << "Enter the source node: ";
    cin >> src;
    cout << "Enter the destination node: ";
    cin >> dest;

    vector<int> visited(v, 0);
    vector<int> path;

    if (dfs(adjList, src, dest, visited, path))
    {
        cout << "Path exists: ";
        for (int i : path)
            cout << i << " ";
        cout << endl;
    }
    else
    {
        cout << "Path does not exist" << endl;
    }

    return 0;
}
