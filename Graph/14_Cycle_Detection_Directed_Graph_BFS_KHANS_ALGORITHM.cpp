#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include <utility>
#include<cstring>
using namespace std;

bool Toposort(vector<int> adj[],int n)
{
    queue<int> q;
    vector<int> indegree(n+1,0);
    for (int i=1;i<=n;i++)
    {
        for (auto it: adj[i])
            indegree[it]++;
    }
    for (int i=1;i<=n;i++)
    {
        if (indegree[i]==0)
           q.push(i);
    }

    int count=0;

    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        count++;
        for (auto it:adj[node])
        {
            indegree[it]--;
            if (indegree[it]==0)
               q.push(it);
        }
    }

    if (count==n)
       return false;
    else
       return true;
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
    if (Toposort(adj,n))
       cout<<"Cycle Detected"<<endl;
    else
       cout<<"No Cycle Detected"<<endl;
       

}
