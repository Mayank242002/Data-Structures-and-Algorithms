#include<bits/stdc++.h>
using namespace std;
 
int bfs(vector<vector<int>> &adj,int n,int m,int r,int c,int ll,int rr)
{
    deque<tuple<int,int,int,int>> dq;
    vector<vector<int>> vis(n,vector<int> (m,0));
    dq.push_front({r,c,ll,rr});
    int ans=0;
    while (!dq.empty())
    {
        auto [a,b,x,y]=dq.front();
        dq.pop_front();
        if (a<0 || a>=n || b<0 || b>=m || adj[a][b]==0 || vis[a][b] ||  x<0 || y<0)
          continue;
        vis[a][b]=1;
        ans++;
        //because these cells are exactly same distance  far  from  source node as front node in queue 
        dq.push_front({a+1,b,x,y});
        dq.push_front({a-1,b,x,y});
        dq.push_back({a,b-1,x-1,y});
        dq.push_back({a,b+1,x,y-1});
    }
    return ans;
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    int r,c;
    cin>>r>>c;
    r--;c--;
    int ll,rr;
    cin>>ll>>rr;
    vector<vector<int>> adj(n,vector<int> (m,1));
    for (int i=0;i<n;i++)
    {
        int j=0;
       string s;
       cin>>s;
       for (char c:s)
         adj[i][j++]=('.'==c);
       
    }
    
    
    cout<<bfs(adj,n,m,r,c,ll,rr)<<endl;
}