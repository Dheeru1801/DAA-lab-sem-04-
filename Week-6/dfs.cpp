#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

//for directed graph
void adj_list(list<int> adj[], int s, int d)
{
    adj[s].push_back(d);
    
}


//dfs traversal 

// void dfs(list<int> adj[], int src,vector<int>&visited)
// {
//     stack<int> s;
//     s.push(src);
//     visited[src] = 1;

//     while (!s.empty())
//     {
//         src = s.top();
//         s.pop();
//         cout << src << " ";
        

//         for (auto a : adj[src])
//         {
//             if (visited[a] != 1)
//             {
//                 dfs(adj,a,visited);
//             }
//         }
//     }
// }


//finding and printing path between source and destination
bool dfs(list<int> adj[], int src, int dest, vector<int> &visited, vector<int> &path)
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

        for (auto a : adj[src])
        {
            if (visited[a] != 1)
            {
                visited[a] = 1;
                if (dfs(adj, a, dest, visited, path)) 
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
    int v = 5;
    list<int> adj[v];
    vector<int>visited(v,0);
    adj_list(adj, 0, 1);
    adj_list(adj, 0, 3);
    adj_list(adj, 1, 4);
    adj_list(adj, 2, 1);
    adj_list(adj, 2, 3);
    adj_list(adj, 2, 4);
    adj_list(adj, 3, 1);
    adj_list(adj, 4, 3);
    int src,dest;
    cout<<"Enter the source node : ";
    cin>>src;
    cout<<"Enter the destination node : ";
    cin>>dest;
    vector<int>path;
    dfs(adj,src,dest,visited,path);
    if(visited[dest]!=1)
    {
        cout<<"Path do no exist"<<endl;
    }
    else
    {
        cout<<"Path exist : ";
        for(int i:path)
            cout<<i<<" ";
    }
    return 0;
}