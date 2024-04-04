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

bool detect(int src, list<int> adj[], vector<int> &visited)
{
    visited[src] = 1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjecentNode:adj[node])
        {
            if(visited[adjecentNode]!=1)
            {
                visited[adjecentNode]=1;
                q.push({adjecentNode,node});
            }
            else if(adjecentNode!=parent)
                return true;    
        }
    }

    return false;
}

bool isCycle(list<int> adj[], int v)
{
    vector<int> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if(visited[i]!=1)
        {
            if (detect(i, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{
    int v = 9;
    list<int> adj[v];

    adj_list(adj, 1, 2);
    adj_list(adj, 1, 3);
    adj_list(adj, 2, 5);
    adj_list(adj, 3, 4);
    adj_list(adj, 3, 6);
    adj_list(adj, 5, 7);
    adj_list(adj, 6, 7);
    

    if(isCycle(adj,v))
    {
        cout<<"Cycle found"<<endl;
    }
    else
        cout<<"No cycle formed"<<endl;

        return 0;
}