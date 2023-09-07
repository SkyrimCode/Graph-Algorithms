/*
Disjoint set is used to find if 2 nodes are part of same component in graph.
It does this in constant time, avoiding a full DFS traversal on a dynamic graph.
It has 2 main operations:
findParent(node)-> 
To check who is the root node. We can optimize the O(logn) traversal of each node
to find the root by using path compression. So whenever we traverse from a leaf
node to root, we keep updating the parent node for all the nodes, so that next time
we can access it in O(1)

Union->Connects 2 nodes by rank or size

By Rank: Connect smaller ranked parent to higher ranked parent.
Why? 
So that in path compression, less no of nodes have to cover the full distance.
If both rank equal, connect any to any. But increase rank of whoever you choose root by 1.

By Size: Connect smaller sized component to higher sized component. When 2 components are 
merged, size of parent(larger comp) increases by size of child(smaller comp).

Note: Size doesn't increase by 1
*/
#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
    vector<int> size;
public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findUParent(int node)
    {
        if(parent[node]==node)
            return node;
        return parent[node]=findUParent(parent[node]);
    }
    
    void unionByRank(int u,int v)
    {
        int parU=findUParent(u);
        int parV=findUParent(v);
        if(parU==parV)  return; //Already connected
        
        if(rank[parU]<rank[parV])
            parent[parU]=parV;
        else if(rank[parV]<rank[parU])
            parent[parV]=parU;
        else
            parent[parV]=parU,rank[parU]++;
    }
    void unionBySize(int u,int v)
    {
        int parU=findUParent(u);
        int parV=findUParent(v);
        if(parU==parV)  return; //Already connected
        
        if(size[parU]<size[parV])
            parent[parU]=parV,size[parV]+=size[parU];
        else
            parent[parV]=parU,size[parU]+=size[parV];
    }
};

int main() {
	DisjointSet ds(7);
	ds.unionBySize(1,2);
	ds.unionBySize(2,3);
	ds.unionBySize(4,5);
	ds.unionBySize(6,7);
	ds.unionBySize(5,6);
	if(ds.findUParent(3)==ds.findUParent(7))
	    cout<<"Connected\n";
	else
	    cout<<"Not Connected\n";
	ds.unionBySize(3,7);
	if(ds.findUParent(3)==ds.findUParent(7))
	    cout<<"Connected\n";
	else
	    cout<<"Not Connected\n";
	
	return 0;
}