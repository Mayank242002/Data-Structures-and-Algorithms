#include<iostream>
using namespace std;

//graph using adjancency matrix O(n2)

int main()
{
    int n,m;         //n=no of Vertices, m= no of lines of edges 
    cout<<"enter n and m"<<endl;
    cin>>n>>m;
    int adj[n+1][n+1];

    for (int i=1;i<=m;i++)
    {
        int u,v;  //ex:- (2,3) is one line which mens there is a edge beetween 2 and 3
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;

    }

    return 0;
}