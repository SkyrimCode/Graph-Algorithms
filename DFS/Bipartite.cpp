/*Bipartite Graph - Graph that can be colored with 2 colors provided no 2 adjacent nodes have same color / If graph doesn't have odd length cycle it is bipartite.

Logic: Keep coloring adjacent uncolored node opposite of current node color. If adjacent node is colored and same as current node, graph is not bipartite.
*/
#include<bits/stdc++.h>
using namespace std;

bool dfs(int i,vector<int> adj[],vector<int> &color,int c)
{
    color[i]=c;
    for(auto x:adj[i])
    {
        if(color[x]==-1)
        {
           if(dfs(x,adj,color,1-c)==false)
            return false;
        }
        else if(color[x]==color[i])
            return false;
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
            if(dfs(i,adj,color,1)==false)
                {
                    cout<<"Graph is not Bipartite\n";
                    return 0;
                }
        }

    }
    cout<<"Bipartite Graph\n";

}
