#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//graph using adjancency list O(n2)

int main()
{
    int n,m;         //n=no of Vertices, m= no of lines of edges 
    cout<<"enter n and m"<<endl;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];

    for (int i=1;i<=m;i++)
    {
        int u,v,wt;          //ex:- (2,3,7) is one line which mens there is a edge beetween 2 and 3
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});  
    }

    int parent[n],key[n];
    bool mstset[n];

    for (int i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mstset[i]=false;
        parent[i]=-1;
    }
    int main_node=0,min_weight=INT_MAX;
    for (int i=0;i<n;i++)
    {
        for (auto it: adj[i])
        {
            int node=it.first;
            int weight=it.second;
            if (weight<min_weight)
            {
                min_weight=weight;
                main_node=node;
            }
        }
    }
    key[main_node]=0;
    parent[main_node]=main_node;
    for (int count=0;count<n-1;count++)
    {
        int mini=INT_MAX,u;
        for (int v=0;v<n;v++)
        {
            if (mstset[v]==false && key[v]<mini)
            {
                mini=key[v];u=v;
            }
        }

        mstset[u]=true;

        for (auto it: adj[u])
        {
            int node=it.first;
            int weight=it.second;

            if (mstset[node]==false && weight<key[node])
            {
                parent[node]=u;
                key[node]=weight;
            }
        }

    }
    printf("Minimum Spanning edges:\n");
    for (int i=0;i<n;i++)
        cout<<parent[i]<<"-"<<i<<"\n";

    return 0;
}