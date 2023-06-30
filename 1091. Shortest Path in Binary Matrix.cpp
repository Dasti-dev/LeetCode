class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        dist[0][0] = 1;
        while(!q.empty())
        {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int step = q.front().first;
            // distance mention
            q.pop();
            for(int i = -1 ; i <= 1 ; i++)
            {
                for(int j = -1 ; j <= 1 ; j++)
                {
                    int nx = x+i;
                    int ny = y+j;
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny] == 0 && step+1 < dist[nx][ny])
                    {
                        dist[nx][ny] = step+1;
                        q.push({step+1,{nx,ny}});
                    }
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX)
        {
            return -1;
        }
        else
        {
            return dist[n-1][n-1];
        }
    }
};
