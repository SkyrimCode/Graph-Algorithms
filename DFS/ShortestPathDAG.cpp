/*Find the shortest path from src node to all other nodes

We store weights as second element of pair in adjacency list. So if edge 1->2 has weight 5 adj[1] = {2,5}

Logic: We perform topo sort to get the ordering of elements. Then for each node if that node is visited (marked by distance being non Infinity) then from that node we can travel to
to its adjacent nodes and update the min distance accordingly.

*/

/*
Test Case:
6 7
0 1 2
1 2 3
2 3 6
0 4 1
4 2 2
4 5 4
5 3 1
0
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<pair<int,int>> adj[],vector<bool> &visited,stack<int> &s)
{
    visited[i]=1;
    for(auto a:adj[i])
    {
        int x=a.first;
        if(!visited[x])
            dfs(x,adj,visited,s);
    }
    s.push(i);

}

void bfsPath(stack<int> s,vector<int> &distance,vector<pair<int,int>> adj[])
{
    while(!s.empty())
    {
        int t=s.top();
        s.pop();
        if(distance[t]!=INT_MAX)
        {
            for(auto a:adj[t])
            {
                int x=a.first;
                distance[x]=min(distance[x],distance[t]+a.second);
            }
        }
    }

}

int main()
{
    int n,m;  cin>>n>>m;
    vector<pair<int,int>> adj[n];
    stack<int> s;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    int src;    cin>>src;
    vector<bool> visited(n,0);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,s);
        }

    }
    vector<int> distance(n,INT_MAX);
    distance[src]=0;
    bfsPath(s,distance,adj);

    for(int i=0;i<n;i++)
        cout<<distance[i]<<" ";
}
