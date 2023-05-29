#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//graph using adjancency list O(n2)
void dfs(int node,int parent,vector<int> &vis,vector<int> &in,vector<int> &low,int &timer,vector<int> adj[])
{
    vis[node]=1;
    in[node]=low[node]=timer++;
    for (auto it:adj[node])
    {
        if (it==parent) continue;
        else if (vis[it]==1)
        {
            low[node]=min(low[node],in[it]);  //back edge is present so update the low (which simply indicates another route is present to that node )
        }
        else
        {
            dfs(it,node,vis,in,low,timer,adj);
            low[node]=min(low[node],low[it]);  //(if child low gets updated due to back edge then parent low also get updated because there is another way to reach parent)
            if (low[it]>in[node])   //(it would be only possible if there is only way to react child node)
                 cout<<node<<" - "<<it<<" is a bridge\n";
        }
    }

}
int main()
{
    int n,m;         //n=no of Vertices, m= no of lines of edges 
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
    vector<int> in(n+1,-1);
    vector<int> low(n+1,-1);
    int timer=0;
    vector<int> vis(n+1,0);
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            dfs(i,-1,vis,in,low,timer,adj);
        }
    }
    return 0;
}