/*Detect whether there is a cycle in directed graph
                                                                                                            / >3 -> 4
Here we need an extra array dfsVis to keep track whether a node was visited in current dfs call. eg: 1 -> 2         |
                                                                                                            \ >5 -> 6
From 2, we mark 3,4,6 as visited in visited[] and dfsVis[] array as it goes to depth.Beyond 6 no path so we unmark dfsVis[] to 0. From 2 again we traverse 5,6. We see 6
was visited before,but from another direction and hence dfsVis[6]=0 in current call, so cycle doesn't exist.
*/
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int> adj[],vector<bool> &visited,vector<bool> &dfsVis)
{
    visited[node]=1;
    dfsVis[node]=1;
    for(auto x: adj[node])
    {
        if(!visited[x])
            {
                if(dfs(x,adj,visited,dfsVis))
                    return true;
            }
        else if(dfsVis[x])  //cycle exists
        {
            return true;
        }
    }
    dfsVis[node]=0;
    return false;
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
    }
    vector<bool> visited(n+1,0),dfsVis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,adj,visited,dfsVis))
                {
                    cout<<"Cycle Exists\n";
                    return 0;
                }
        }

    }
    cout<<"No Cycle detected\n";

}
