/*Topo Sort is linear ordering of edges such that if there is an edge u->v u appears before v in the ordering.

Topo Sort gives the correct ordering of all nodes in DAG only. If graph is undirected we dont know edge is from u->v or v->u. If graph is cyclic we can't
identify the source node, i.e we can't say any 1 node should appear before the other one in cycle in the Topo Sort.

Logic:For each source node, go to its deepest depth and while exiting from deepest level push it to stack.That way the deepest node,i.e
one at the end of the chain is inserted at bottom of stack and the first source node is at top. Thus topo sort property is maintained.
*/

/*
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

void dfs(int i,vector<int> adj[],vector<bool> &visited,stack<int> &s)
{
    visited[i]=1;
    for(auto x:adj[i])
    {
        if(!visited[x])
            dfs(x,adj,visited,s);
    }
    s.push(i);

}

int main()
{
    int n,m;  cin>>n>>m;
    vector<int> adj[n];
    stack<int> s;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<bool> visited(n,0);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,s);
        }

    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}
