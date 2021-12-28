#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj[],vector<bool> &visited,vector<int> &res)
{
    visited[node]=1;
    res.push_back(node);
    for(auto x: adj[node])
    {
        if(!visited[x])
            dfs(x,adj,visited,res);
    }
}

int main()
{
    int n,m;  cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1,0);
    vector<int> res;    //stores DFS traversal
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            dfs(i,adj,visited,res);
    }
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}
