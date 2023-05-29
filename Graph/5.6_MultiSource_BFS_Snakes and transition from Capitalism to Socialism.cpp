#include <bits/stdc++.h>
using namespace std;

 bool isvalid(int x, int y, int m, int n)
 {
    if (x < 0 or y < 0 or x >= m or y >= n)
       return 0;
    return 1;
  }
int bfs(vector<vector<int>> &arr,int n,int m,int maxi)
{
    vector<vector<int>> vis(n,vector<int> (m,0));
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (arr[i][j]==maxi)
            {
                q.push({{i,j},0});
                vis[i][j]=1;
            }
        }
    }
    int curr_level=0;
    while (!q.empty())
    {
        int node_x=q.front().first.first;
        int node_y=q.front().first.second;
        int level=q.front().second;
        curr_level=max(curr_level,level);
        q.pop();
        
        for (int i=0;i<8;i++)
        {
            int new_x=node_x+dir[i][0];
            int new_y=node_y+dir[i][1];
            
            if (isvalid(new_x,new_y,n,m) && vis[new_x][new_y]==0)
            {
                q.push({{new_x,new_y},level+1});
                vis[new_x][new_y]=1;
            }
        }
        
    }
    
    return curr_level;
}


int main() {
	int t;
	cin>>t;
	while (t--)
	{
	    int n, m;
	    cin>>n>>m;
	    vector<vector<int>> arr(n,vector<int> (m));
	    int maxi=1;
	    for (int i=0;i<n;i++)
	    {
	        for (int j=0;j<m;j++)
	        {
	            cin>>arr[i][j];
	            maxi=max(maxi,arr[i][j]);
	        }  
	    }
	        
	   cout<<bfs(arr,n,m,maxi)<<endl;
	}
	return 0;
}