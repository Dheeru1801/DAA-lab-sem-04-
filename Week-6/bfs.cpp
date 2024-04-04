#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

// adjecency list for undirected graph
void adj_list(list<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

// bfs traversal

// void bfs(list<int> adj[], int src, int v)
// {
//     vector<int> visited(v, 0);
//     queue<int> q;
//     q.push(src);
//     visited[src] = 1;

//     while (!q.empty())
//     {
//         src = q.front();
//         cout << src<<" ";
//         q.pop();
//         for (auto a : adj[src])
//         {
//             if (visited[a] != 1)
//             {
//                 q.push(a);
//                 visited[a] = 1;
//             }
//         }
//     }
// }

bool isBipartite(list<int>adj[],int src,int v)
{
    //initially not colored
    vector<int>color(v,-1);
    queue<int>q;

    q.push(src);
    color[src]=0;

    while(!q.empty())
    {
        src=q.front();
        q.pop();
        for(auto a:adj[src])
        {
            if(color[a]==-1)
            {
                color[a]=1-color[src];
                q.push(a);
            }
            else if(color[a]==color[src])
                return false;
        }
    }
    return true;

} 

int main()
{
    int v = 9;
    list<int> adj[v];

    adj_list(adj, 1, 2);
    adj_list(adj, 2, 3);
    adj_list(adj, 2, 6);
    adj_list(adj, 3, 4);
    adj_list(adj, 4, 5);
    adj_list(adj, 4, 7);
    adj_list(adj, 5, 6);
    adj_list(adj, 7, 8);


    if(isBipartite(adj, 1, v))
        cout<<"The graph is Bipartite"<<endl;
    else
        cout<<"The graph is not Bipartite"<<endl;
    return 0;
}