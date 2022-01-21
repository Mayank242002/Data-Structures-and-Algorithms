#include<iostream>
#include<vector>
#include <utility>
#include<stack>
using namespace std;

//Directedgraph using adjancency matrix O(n2)
void topodfs(int node, stack<int> &st,vector<int> &vis,vector<int> adj[])
{
    vis[node]=1;
    for (auto it: adj[node])
    {
        if (vis[it]==0)
           topodfs(it,st,vis,adj);
    }
    st.push(node);
}

void revdfs(int node,vector<int> &vis,vector<int> transpose[])
{
    cout<<node<<" ";
    vis[node]=1;
    for (auto it: transpose[node])
    {
        if (!vis[it])
        {
            revdfs(it,vis,transpose);
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
    }

     stack<int> st;
     vector<int> vis(n+1,0);
     for (int i=1;i<=n;i++)
     {
         if (!vis[i])
            topodfs(i,st,vis,adj);
     }

     vector<int> transpose[n+1];
     for (int i=1;i<=n;i++)
     {
         vis[i]=0;
         for (auto it: adj[i])
         {
             transpose[it].push_back(i);
         }
     }

     while (!st.empty())
     {
        int node=st.top();
        st.pop();
        if (!vis[node])
        {
            cout<<"SCC: ";
            revdfs(node,vis,transpose);
            cout<<endl;
        }

     }
    return 0;
}