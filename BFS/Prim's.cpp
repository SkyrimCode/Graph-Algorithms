/*Finds the minimum spanning tree for given graph. MST is a spanning tree whose sum of cost of weights of edges is minimum and the edges connect ALL nodes. SO for N nodes we
need N-1 edges to connect all nodes and those N-1 edges should be of min weight and connect all nodes at the same time.

Logic: We maintain 3 arrays - key[] to store min weight to reach node i, parent[] to store parent node of ith node, mst[] to keep track of all visited nodes.
We iterate through the key[] array to find unvisited node with min weight ( Such a node is either starting node or adjacent to a visited node(that is how key got populated)).

Once we get a node, we visit its adjacent nodes and if they are unvisited and the corresponding edge weight is less, we update their key and set their parent value to current
node, but don't include them in our MST yet, since we will loop through all key values in next iteration.

In general, we start from 0, check its adjacent edges and pick the one with min weight and add to MST. Remaining edges and the new adjacent nodes' adjacent edges weight are taken
into consideration in the next iteration to find next min weight.

Test Case:
5 6
0 1 2
1 2 3
0 3 6
1 3 8
1 4 5
2 4 7

6 9
5 4 9
5 1 4
1 4 1
4 3 5
4 2 3
1 2 2
2 3 3
3 0 8
2 0 7
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;  cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> key(n,INT_MAX); //key[i] stores the min weight to reach node i.
    key[0]=0;
    vector<bool> mst(n,false);
    vector<int> parent(n,-1);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  // {weight,node} Sorted in ascending order of weight so min weight at top
    pq.push({0,0});
    //For n nodes we need n-1 edges for MST. So we iterate n-1 times
    for(int i=0;i<n-1;i++)
    {
        //For O(n^2) use a loop to get min key value node
        /*
        int mini=INT_MAX,node;
        for(int j=0;j<n;j++)
            if(!mst[j] and key[j]<mini)
                mini=key[j],node=j;
        */

        //For O(n log n) use priority queue to get min key value node
        int node=pq.top().second;
        pq.pop();

        mst[node]=1;

        for(auto x: adj[node])
        {
            int t=x.first,w=x.second;
            if(!mst[t] and w<key[t])
                key[t]=w,parent[t]=node,pq.push({key[t],t});
        }
    }
    for(int i=1;i<n;i++)
        cout<<parent[i]<<" - "<<i<<"\n";

}

