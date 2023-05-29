bool valid(int x, int y, int m, int n){
        if (x < 0 or y < 0 or x == m or y == n)    return 0;
        return 1;
    }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        dq.push_front({0,0});
        dist[0][0]=0;
        vector<vector<int>>dirs = {{0,1,1},{0,-1,2},{1,0,3},{-1,0,4}};
        
        while (!dq.empty())
        {
            auto node=dq.front();
            dq.pop_front();
            int x=node.first,y=node.second;
            for (auto dir:dirs)
            {
                int new_x = x+dir[0], new_y = y+dir[1];
                int weight = (dir[2] == grid[x][y]) ? 0 : 1;
                if (valid(new_x, new_y, m, n))
                {
                    if (dist[new_x][new_y]>dist[x][y]+weight)
                    {
                        dist[new_x][new_y]=dist[x][y]+weight;
                        if (weight)
                          dq.push_back({new_x, new_y});
                        else
                          dq.push_front({new_x, new_y});
                    } 
                }
            }
        }
        
        return dist[m-1][n-1];
    }