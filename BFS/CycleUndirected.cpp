/*Detect whether there is a cycle in undirected graph

Traverse all adjacent nodes of a node N and if any of the node is visited and is not the parent of current node N, it means there exists a cycle.
*/
#include<bits/stdc++.h>
using namespace std;

bool bfs(int node,int parent,vector<int> adj[],vector<bool> &visited,vector<int> &res)
{
    visited[node]=1;
    queue<pair<int,int>> q;
    q.push({node,parent});

    while(!q.empty())
    {
        pair<int,int> t=q.front();
        res.push_back(t.first);
        q.pop();
        for(auto x:adj[t.first])
        {
            if(!visited[x])
                visited[x]=1,q.push({x,t.first});
            else if(x!=t.second)
            {
                res.push_back(x);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n,m;  cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> res;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(bfs(i,-1,adj,visited,res))
                {
                    cout<<"Cycle Exists\n";
                    for(int i=0;i<res.size();i++)
                        cout<<res[i]<<" ";
                    return 0;
                }
        }

    }
    cout<<"No Cycle detected\n";

}
