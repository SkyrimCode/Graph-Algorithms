/*Finds shortest path distance between source node to all other nodes

Logic: Keep distance to all nodes as Infinity except source node(0)
From src node travel all adjacent nodes and update the distance. If updated then push to queue,since this new short distance may update its adjacent node distances.

Test Case:
9 11
0 1
0 3
1 3
1 2
2 6
3 4
4 5
5 6
6 7
7 8
8 6
0
*/

#include<bits/stdc++.h>
using namespace std;

void bfs(int src,vector<int> adj[],vector<int> &distance)
{
    queue<int> q;
    q.push(src);
    distance[src]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto x: adj[t])
        {
            if(1+distance[t]<distance[x])
                distance[x]=1+distance[t],q.push(x);
        }
    }
}

int main()
{
    int n,m;  cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;    cin>>src;
    vector<int> distance(n,INT_MAX);
    bfs(src,adj,visited,distance);

    for(int i=0;i<distance.size();i++)
        cout<<distance[i]<<" ";
}

