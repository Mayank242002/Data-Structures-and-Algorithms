#include<iostream>
#include<vector>
#include <utility>
#include<queue>
using namespace std;

bool CheckForCycle(int node,int parent,vector<int> adj[],vector<int> &vis)
{
    vis[node]=1;
    for (auto it:adj[node])
    {
        if (vis[it]==0)
        {
            if (CheckForCycle(it,node,adj,vis))
               return true;
        }
        else if (it!=parent)
           return true;
    }

    return false;
}
bool isCycle(vector<int> adj[],int v)   //function so that Code works for non connected graphs also
{
    vector<int> vis(v+1,0);
    for (int i=1;i<=v;i++)
    {
        if (!vis[i])
        {
            if (CheckForCycle(i,-1,adj,vis))
               return true;
        }
    }

    return false;

}

int main()
{
    int n,m;         //n=no of vertices, m= no of lines of edges 
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

    if (isCycle(adj,n))
        cout<<"Cycle Detected";
    else
        cout<<"No cycle Detected";
}