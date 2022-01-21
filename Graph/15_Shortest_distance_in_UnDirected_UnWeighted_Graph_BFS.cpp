#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

void BFS(vector<int> adj[],int n,int src)
{
   int dist[n];
   for (int i=0;i<n;i++)
   dist[i]=INT_MAX;
   queue<int> q;
   dist[src]=0;
   q.push(src);
   while (!q.empty())
   {
       int node=q.front();
       q.pop();
       for (auto it: adj[node])
       {
           if (dist[node]+1<dist[it])
           {
               dist[it]=dist[node]+1;
               q.push(it);
           }
       }
   }
   for (int i=0;i<n;i++)
      cout<<dist[i]<<" ";
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
    BFS(adj,n,0);
    return 0;
}