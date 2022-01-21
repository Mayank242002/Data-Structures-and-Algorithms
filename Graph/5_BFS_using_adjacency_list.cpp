#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//graph using adjancency list O(n2) for connected and non connected graphs

vector<int> BFS(int v,vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(v+1,0);

    for (int i=1;i<=v;i++)
    {
        if (vis[i]==0)
        {
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while (!q.empty())
            {
                int node=q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it:adj[node])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }

    return bfs;
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

    vector<int> ans=BFS(n,adj);
    for (int i=0;i<ans.size();i++)
       cout<<ans[i]<<" ";

    return 0;
}