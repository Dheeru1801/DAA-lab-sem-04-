/*
NAME: AASHNAN GOYAL
SECTION: DS1
ROLL NO.: 2
UNIVERSITY ROLL NO.: 2021632
*/

// Q3.Given a directed graph with two vertices(source and destination).Design an algorithm and implement it using a program to find the weight of the shortest path from source to destination with exactly k edges on the path.Soln :
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int shortestPathWithKEdges(vector<vector<int>> &graph, int source, int destination, int k)
{
    int V = graph.size();
    vector<vector<int>> dp(V, vector<int>(k + 1, INT_MAX));
    dp[source][0] = 0;
    for (int edge = 1; edge <= k; edge++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] != INT_MAX && dp[u][edge - 1] != INT_MAX)
                {
                    dp[v][edge] = min(dp[v][edge], dp[u][edge - 1] + graph[u][v]);
                }
            }
        }
    }
    if (dp[destination][k] != INT_MAX)
    {
        return dp[destination][k];
    }
    else
    {
        return -1;
    }
}
int main()
{
    int V;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }
    int source, destination, k;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;
    cout << "Enter the value of k: ";
    cin >> k;
    int shortestPathWeight = shortestPathWithKEdges(graph, source - 1, destination - 1, k);
    if (shortestPathWeight != -1)
    {
        cout << "Weight of shortest path from (" << source << "," << destination << ") with " << k << " edges: " << shortestPathWeight << endl;
    }
    else
    {
        cout << "No path of length " << k << " is available." << endl;
    }

    return 0;
}
