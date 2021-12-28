/*Kruskal's algorithm finds the minimum spanning tree for given graph. MST is a spanning tree whose sum of cost of weights of edges is minimum and the edges connect ALL nodes. SO for N nodes we
need N-1 edges to connect all nodes and those N-1 edges should be of min weight and connect all nodes at the same time.

Logic: We sort edges by weights and pick from minimum weight and connect the components. If new edge belongs to same component it is not taken as it would form cycle thereby violating tree property.
To check whether they belong to same component we use disjoint set DS. Once all edges are iterated, we get MST.

TC - Mlog(M) for sorting M edges and M*4alpha for fetching parent using disjoint set.

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

struct node{
    int u,v,w;
    node(int first,int second,int weight)
    {
        u=first;
        v=second;
        w=weight;
    }
};

bool cmp(node a,node b)
{
    return a.w<b.w;
}

int findParent(int n,vector<int> &parent)
{
    if(n==parent[n])    return n;
    return parent[n]=findParent(parent[n],parent);
}

void unionn(int u,int v,vector<int> &parent,vector<int>&rankk)
{
    u=findParent(u,parent);
    v=findParent(v,parent);
    if(rankk[u]<rankk[v])   //height of v's subtree is more so u can be accomodated on one side of it
        parent[u]=v;
    else if(rankk[v]<rankk[u])
        parent[v]=u;
    else
        parent[v]=u,rankk[u]++;
}

int main()
{
    int n,m;  cin>>n>>m;
    vector<node> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(node(u,v,w));
    }
    sort(edges.begin(),edges.end(),cmp);
    vector<int> parent(n),rankk(n,0);
    int cost=0;
    for(int i=0;i<n;i++)
        parent[i]=i;
    vector<pair<int,int>> mst;
    for(auto it:edges)
    {
        if(findParent(it.u,parent)!=findParent(it.v,parent))
        {
            cost+=it.w;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v,parent,rankk);
        }
    }
    cout<<"Cost = "<<cost<<"\n";
    for(auto it: mst)
        cout<<it.first<<" - "<<it.second<<"\n";

}

