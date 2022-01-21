#include<iostream>
#include<vector>
#include <utility>
#include<cstring>
#include<stack>
#include<limits.h>
using namespace std;



void findToposort(int node,vector<pair<int,int>> adj[],stack<int> &st,int vis[])
{
    vis[node]=1;
    for (auto it: adj[node])
    {
        if (!vis[it.first])
        {
            findToposort(it.first,adj,st,vis);
        }
    }
    st.push(node);
}

void ShortestPath(int src,int N,vector<pair<int,int>> adj[])
{
    int vis[N];

    for (int i=0;i<N;i++)
            vis[i]=0;
    stack<int> st;
    for (int i=0;i<N;i++)
    {
        if (!vis[i])
        {
            findToposort(i,adj,st,vis);

        }

    }
    int dist[N];
    
    for (int i=0;i<N;i++)
            dist[i]=INT_MAX;
    dist[src]=0;
    while (!st.empty())
    {
        int node=st.top();
        st.pop();
        if (dist[node]!=INT_MAX)
        {
            for (auto it: adj[node])
            {
                if (dist[node]+it.second<dist[it.first])
                    dist[it.first]=dist[node]+it.second;
            }
        }
    }

    for (int i=0;i<N;i++)
       cout<<dist[i]<<" ";
         

}

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
        //adj[v].push_back({u,wt});   for undirected_weighted graph
    }
    ShortestPath(0,n,adj);

    return 0;
}