#include <bits/stdc++.h>
using namespace std;

void adjListFromMatrix(list<pair<int, int>> adj[], vector<vector<int>> &matrix, int v)
{
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            if (matrix[i][j] != 0) // if there is an edge
            {
                adj[i].push_back({j, matrix[i][j]});
                adj[j].push_back({i, matrix[i][j]}); // because it's an undirected graph
            }
        }
    }
}

// for max profit
int prims(vector<vector<int>> &matrix, int v, int start)
{
    int weight = 0;
    list<pair<int, int>> adj[v];
    adjListFromMatrix(adj, matrix, v);

    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    vector<int> visited(v, 0);

    // {weight,node}
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
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    vector<vector<int>> matrix(v, vector<int>(v, 0));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    int maxProfit = prims(matrix, v, 0);
    cout << "Maximum profit for the MST is : " << maxProfit << endl;

    return 0;
}
