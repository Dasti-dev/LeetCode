class Solution {
private:
    void bfs ( int row , int col , vector<vector<int>> &vis , vector<vector<char>> &grid)
    {
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int drow[] = {0,-1,0,1};
            int dcol[] = {-1,0,1,0};
            
                for(int j = 0 ; j < 4 ; j++)
                {
                    int nrow = row + drow[j];
                    int ncol = col + dcol[j];
                    if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol] && grid[row][col] == '1')
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int> (m,0));
        int cnt = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};
