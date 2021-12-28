/*Bipartite Graph - Graph that can be colored with 2 colors provided no 2 adjacent nodes have same color / If graph doesn't have odd length cycle it is bipartite.

Logic: Keep coloring adjacent uncolored node opposite of current node color. If adjacent node is colored and same as current node, graph is not bipartite.
*/
#include<bits/stdc++.h>
using namespace std;

bool bfs(int i,vector<int> adj[],vector<int> &color)
{
    color[i]=1;
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto x:adj[node])
        {
            if(color[x]==-1)
                color[x]=1-color[node],q.push(x)    ;
            else if(color[x]==color[node])
                return false;
        }
    }
    return true;
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
    vector<int> color(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            if(bfs(i,adj,color)==false)
                {
                    cout<<"Graph is not Bipartite\n";
                    return 0;
                }
        }

    }
    cout<<"Bipartite Graph\n";

}
