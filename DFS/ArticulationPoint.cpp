/*Articulation Point are those nodes which if we remove we get separate components.

Logic: We start from a node and go deeper using DFS setting its time of insertion and lowest time of insertion.Once we have visited all unvisited nodes and return back from recursive
call we update low as minimum of low[node] and low of the adjacent visited node which was visited from some other path possibly. If low of adjacent node is more than equals
current node's insertion time, it means adjacent node was visited after current node through current node.So current node is an articulation point.

If adjacent node is visited we update low for current node.
6 6
1 2
1 4
2 3
3 4
4 5
5 6
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,vector<int> &visited,vector<int> &tin,vector<int> &low,int &timer,vector<int> adj[],vector<int> &articulation)
{
    visited[node]=1;
    tin[node]=low[node]=timer++;
    int child=0;
    for(auto x: adj[node])
    {
        if(x==parent)   continue;   //We don't go back before we have visited its depth.
        if(!visited[x])
        {
            dfs(x,node,visited,tin,low,timer,adj,articulation);
            low[node]=min(low[node],low[x]);
            if(low[x]>=tin[node] and parent!=-1)
                articulation[node]=1;
            child++;        //Counting individual disconnected childs for root node
        }
        else
            low[node]=min(low[node],tin[x]);
    }
    if(parent==-1 and child>1)  //If root node has more than 1 disconnected child removing root node will result in separate components hence root node becomes articulation point.
        articulation[node]=1;
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
    vector<int> visited(n+1,0),tin(n+1,-1),low(n+1,-1),articulation(n+1,0);
    int timer=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i,-1,visited,tin,low,timer,adj,articulation);
        }

    }
    for(int i=1;i<=n;i++)
        if(articulation[i])
            cout<<i<<"\n";
}
