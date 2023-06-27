class Solution {
private:
    void dfs (int row ,int col , vector<vector<int>> &grid , vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        int drow[] = {0,-1,0,1};
        int dcol[] = {-1,0,1,0};
        for(int i = 0 ; i < 4 ; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow,ncol,grid,vis);
            }
        }

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if( i==0 || i==(n-1) || j==0 || j==(m-1))
                {
                    if(grid[i][j] == 1 && !vis[i][j])
                    {
                        dfs(i,j,grid,vis);
                    }
                }
            }
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
