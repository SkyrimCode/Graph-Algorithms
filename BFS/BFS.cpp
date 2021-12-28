#include<bits/stdc++.h>
using namespace std;

void bfs(int node,vector<int> adj[],vector<bool> &visited,vector<int> &res)
{
    visited[node]=1;
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int t=q.front();
        res.push_back(t);
        q.pop();
        for(auto x: adj[t])
        {
            if(!visited[x])
                visited[x]=1,q.push(x);
        }

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
    vector<int> res;    //stores BFS traversal
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            bfs(i,adj,visited,res);
    }
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}
