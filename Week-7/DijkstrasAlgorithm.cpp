#include<bits/stdc++.h>
using namespace std;

void dijsktrasAlgo(list<pair<int,int>>adj[],vector<int>&dis,vector<int>&dummyParent,int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //{dis,node}

    dis[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int node=pq.top().second;
        int weight=pq.top().first;
        pq.pop();

        for(auto adjNode:adj[node])
        {
            int edgeNode=adjNode.first;
            int edgeWeight=adjNode.second;
            if(weight+edgeWeight<dis[edgeNode])
            {
                ///updating the parent vector
                dummyParent[edgeNode]=node;
                dis[edgeNode]=weight+edgeWeight;
                pq.push({dis[edgeNode],edgeNode});
            }
        }
    }
}

void ultimateParent(vector<int>&parent,int node)
{
    if(parent[node]==node)
    {
        cout<<node;
        return;
    }
    ultimateParent(parent,parent[node]);
    cout<<"->"<<node;
    
}

void adjList(list<pair<int,int>>adj[],int s,int d,int w)
{
    adj[s].push_back({d,w});
    adj[d].push_back({s,w});
}

int main()
{
    int v=6;
    list<pair<int,int>>adj[v];
    vector<int>dis(v,INT_MAX);

    //adding parent vector to calculate the path
    vector<int>dummyParent(v);
    for(int i=0;i<v;i++)
        dummyParent[i]=i;

    adjList(adj,0,1,4);
    adjList(adj,0,2,4);
    adjList(adj,1,2,2);
    adjList(adj,2,3,3);
    adjList(adj,2,5,6);
    adjList(adj,2,4,1);
    adjList(adj,3,5,2);
    adjList(adj,4,5,3);

    dijsktrasAlgo(adj,dis,dummyParent,0);

    for(int i=0;i<v;i++)
    {
        ultimateParent(dummyParent,i);
        cout<<" : "<<dis[i];
        cout<<endl;
    }

    return 0;
}