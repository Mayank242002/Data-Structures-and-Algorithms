#include<iostream>
#include<vector>
#include <utility>
#include<queue>
#include<limits.h>
using namespace std;


vector<int> Dijkastra_algo(vector<pair<int,int>> adj[],int src,int n)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distTo(n+1,INT_MAX);
    distTo[src]=0;
    pq.push(make_pair(0,src));
    while (!pq.empty())
    {
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        for (auto it: adj[prev])
        {
            int next=it.first;
            int nextdist=it.second;
            if (distTo[next]>distTo[prev]+nextdist)
            {
                distTo[next]=distTo[prev]+nextdist;
                pq.push(make_pair(distTo[next],next));
            }
        }
    }

    return distTo;

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
        adj[v].push_back({u,wt});   
    }
    vector<int> ans=Dijkastra_algo(adj,1,n);
    for (int i=1;i<ans.size();i++)
       cout<<ans[i]<<" ";

    return 0;
}