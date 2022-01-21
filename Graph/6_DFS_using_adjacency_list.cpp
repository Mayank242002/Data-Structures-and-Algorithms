#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void DFS(int node ,vector<int> &vis,vector<int> adj[],vector<int> &storedfs)
{
    storedfs.push_back(node);
    vis[node]=1;
    for (auto it: adj[node])
    {
        if (!vis[it])
          DFS(it,vis,adj,storedfs);
    }
}
vector<int> DFS_FOR_GRAPH(int v,vector<int> adj[])
{
    vector<int> storedfs;
    vector<int> vis(v+1,0);
    for (int i=1;i<=v;i++)
    {
        if (vis[i]==0)
        {
            DFS(i,vis,adj,storedfs);
        }
    }

    return storedfs;
}

int main()
{
    int n,m;         //n=no of edges, m= no of lines of edges 
    cout<<"enter n and m"<<endl;
    cin>>n>>m;
    vector<int> adj[n+1];

    for (int i=1;i<=m;i++)
    {
        int u,v;          //ex:- (2,3) is one line which mens there is a edge beetween 2 and 3
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans=DFS_FOR_GRAPH(n,adj);
    for (int i=0;i<ans.size();i++)
       cout<<ans[i]<<" ";

    return 0;
}