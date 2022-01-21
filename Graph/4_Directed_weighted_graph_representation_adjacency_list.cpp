#include<iostream>
#include<vector>
#include <utility>
using namespace std;

//Directedgraph using adjancency matrix O(n2)

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
        //adj[v].push_back({u,wt});   for undirected_weighted graph
    }

    return 0;
}