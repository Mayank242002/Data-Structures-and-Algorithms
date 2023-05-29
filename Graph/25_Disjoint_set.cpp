#include<bits/stdc++.h>
using namespace std;

 
 //Disjoint set needs unique edges 
 int find(int x,vector<int> &parent)
    {
        if (parent[x]==x)
          return x;
        else 
          return parent[x]=find(parent[x],parent);
    }

void Union(int a,int b, vector<int> &parent)
    {
        int u=find(a,parent);
        int v=find(b,parent);
        if (u==v)
           return;
        else
           parent[u]=v;
    }


int main()
{
    int n,m;         //n=no of Vertices, m= no of lines of edges 
    cout<<"enter n and m"<<endl;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> parent(n+1);
     for (int i=1;i<=n;i++)
        parent[i]=i;

    for (int i=1;i<=m;i++)
    {
        int u,v;          //ex:- (2,3) is one line which mens there is a edge beetween 2 and 3
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);   //because pushing same edges make Disjoint set not to work accurately.
    }

    for (int i=1;i<=n;i++)
    {
        int flag=0;
        for (int dest:adj[i])
        {
            int u=find(i,parent);
            int v=find(dest,parent);
            if (u==v)
            {
                cout<<"Cycle Present"<<endl;
                flag=1;
                break;
            }
            else{
              Union(u,v,parent);
            }
        }
        if (flag==1)
          break;
    }

    return 0;
}