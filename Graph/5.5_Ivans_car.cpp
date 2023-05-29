#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int v,vector<pair<int,int>> adj[],int src)
{
    vector<int> dist(10010,INT_MAX);
    dist[src]=0;
    deque<int> dq;
    dq.push_back(src);
    while (!dq.empty())
    {
        int node=dq.front();
        dq.pop_front();
        for (auto it:adj[node])
        {
            int u=it.first;
            int w=it.second;
            if (dist[u]>dist[node]+w)
            {
                dist[u]=dist[node]+w;
                if (w==1)
                 dq.push_back(u);
                else
                  dq.push_front(u);
            }
        }
    }
    return dist;
}

int main() {
	int n,m;         //n=no of edges, m= no of lines of edges 
    cin>>n>>m;
    vector<pair<int,int>> adj[10010];
    

    for (int i=1;i<=m;i++)
    {
        int u,v;     
        cin>>u>>v;
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
       
    }
   int src,dst;
   cin>>src>>dst;
   vector<int> ans=BFS(n,adj,src);
   cout<<ans[dst]<<endl;
}