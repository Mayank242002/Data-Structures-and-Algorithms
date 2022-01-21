#include<iostream>
#include<vector>
#include <utility>
#include<queue>
#include<cstring>
using namespace std;
bool BipartiteDFS(int node,vector<int> adj[],int color[])
{
    if (color[node]==-1)
       color[node]=1;

    for (auto it : adj[node])
    {
        if (color[it]==-1)
        {
            color[it]=1-color[node];
            if (BipartiteDFS(it,adj,color)==false)
                return false;
        }
        else if (color[it]==color[node])
            return false;
    }

    return true;
}
bool checkBipartite(vector<int>adj[],int v)
{
   int color[v];
    memset(color,-1,sizeof(color));
    for (int i=1;i<=v;i++)
    {
        if (color[i]==-1)
        {
            if (BipartiteDFS(i,adj,color)==false)
                return false;
        }
        
    }
    return true;
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

    if (checkBipartite(adj,n))
       cout<<"Bipartite Graph";
    else 
       cout<<"Not a Bipartite Graph";

}