
/*Finds shortest path distance between source node to all other nodes

Logic: Keep distance to all nodes as Infinity except source node(0)
We use priority queue to maintain shortest distance on top. We traverse all adjacent nodes for current node and update the distance accordingly. If updated the new node along with
shorter distance is pushed to priority queue as it may update its adjacent element's distance.

Test Case:
5 6
1 2 2
2 5 5
1 4 1
4 3 3
3 2 4
3 5 1
1
*/

#include<bits/stdc++.h>
using namespace std;

void bfs(int src, vector<pair<int,int>> adj[],vector<int> &distance)
{
    priority_queue<pair<int,int>> pq;  // {distance,node} pair is stored in pq
    pq.push({0,src});
    distance[src]=0;
    while(!pq.empty())
    {
        int prev=pq.top().second;   //Previous Node
        int dist=pq.top().first;    //Distance till Previous Node
        pq.pop();
        for(auto x: adj[prev])
        {
            int next=x.first;       //Adjacent next node
            int nextDist=x.second;  //Weight of prev -> next node
            if(nextDist+distance[prev]<distance[next])
            distance[next]=nextDist+distance[prev],pq.push({distance[next],next});
        }
    }
}

int main()
{
    int n,m;  cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src;    cin>>src;
    vector<int> distance(n+1,INT_MAX);
    bfs(src,adj,distance);

    for(int i=1;i<distance.size();i++)
        cout<<distance[i]<<" ";
}

