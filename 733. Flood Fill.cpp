class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        int value = image[sr][sc];
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;

            image[row][col] = color;
            q.pop();

            int drow[] = {0,-1,0,1};
            int dcol[] = {-1,0,1,0};

            for(int i = 0 ; i < 4 ; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && image[nrow][ncol]==value)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }

        }
        return image;
    }
};
