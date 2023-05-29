#include<bits/stdc++.h>
using namespace std;

//graph using adjancency list O(n2) for connected and non connected graphs


//no need for visited as those node will not be relaxed more than one time
vector<int> BFS(int v,vector<pair<int,int>> adj[],int src)
{
    vector<int> dist(v,INT_MAX);
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

int main()
{
    int n,m;         //n=no of edges, m= no of lines of edges 
    cout<<"enter n and m"<<endl;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];

    for (int i=1;i<=m;i++)
    {
        int u,v,wt;          //ex:- (2,3) is one line which mens there is a edge beetween 2 and 3
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<int> ans=BFS(n,adj,0);
    for (int i=0;i<ans.size();i++)
       cout<<ans[i]<<" ";

    return 0;
}