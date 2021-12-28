/*Topo Sort is linear ordering of edges such that if there is an edge u->v u appears before v in the ordering.

Topo Sort gives the correct ordering of all nodes in DAG only. If graph is undirected we dont know edge is from u->v or v->u. If graph is cyclic we can't
identify the source node, i.e we can't say any 1 node should appear before the other one in cycle in the Topo Sort.

Logic: Here we don't need to keep track of visited. We calculate indegrees of all nodes. (Indegree = No. of incoming edges)
We initially push all nodes with indegree 0 to queue, since they are source nodes and they don't have any incoming edge.
We traverse the adjacent nodes of the indegree 0 nodes and reduce their indegree by 1 since we have already considered their source node and placed it before them.
If their indegree becomes 0 then push it to queue.

Test Case:
6 6
5 0
4 0
4 1
5 2
2 3
3 1
*/
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],vector<int> &res,int n)
{
    vector<int> indegree(n,0);
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        for(auto x:adj[i])
            indegree[x]++;
    }
    for(int i=0;i<n;i++)
        if(indegree[i]==0)
            q.push(i);

    while(!q.empty())
    {
        int t=q.front();
        res.push_back(t);
        q.pop();
        for(auto x: adj[t])
        {
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
    }
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
    }

    bfs(adj,res,n);

    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";

}
