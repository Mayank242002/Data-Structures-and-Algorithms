#include<bits/stdc++.h>
using namespace std;

bool CheckForCycle(int start,vector<int> &vis,vector<int> adj[],int v)
{
    queue<pair<int ,int>> q;
    vis[start]=1;
    q.push({start,-1});
    while (!q.empty())
    {
        int node=q.front().first;
        int prev=q.front().second;
        q.pop();
        for (auto it: adj[node])
        {
            if (!vis[it])
            {
                vis[it]=1;
                q.push({it,node});
            }
            else if (it!=prev)
            {
                return true;
            }
        }
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
            if (CheckForCycle(i,vis,adj,v))
               return true;
        }
    }

    return false;

}
//graph using adjancency list O(n2)

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