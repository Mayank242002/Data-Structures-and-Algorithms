#include<iostream>
#include<vector>
#include<stack>
#include <utility>
#include<cstring>
using namespace std;

void findToposort(int node,vector<int> adj[],stack<int> &st,vector<int> &vis)
{
    vis[node]=1;
    for (auto it: adj[node])
    {
        if (!vis[it])
        {
            findToposort(it,adj,st,vis);
        }
    }
    st.push(node);
}
vector<int> Toposort(vector<int> adj[],int n)
{
    stack<int> st;
    vector<int> vis(n,0);
    for (int i=0;i<n;i++)
    {
        if (!vis[i])
        {
            findToposort(i,adj,st,vis);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
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
    vector<int> res=Toposort(adj,n);
    for (int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }

}
