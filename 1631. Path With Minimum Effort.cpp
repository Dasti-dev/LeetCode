class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> qp;
        dist[0][0] = 0;
        qp.push({0,{0,0}});
        int diff = 0; 
        while(!qp.empty())
        {
            int step = qp.top().first;
            int row = qp.top().second.first;
            int col = qp.top().second.second;

            qp.pop();

            if(row == n-1 && col == m-1)
            return step;

            int drow[] = {0,-1,0,1};
            int dcol[] = {-1,0,1,0};

            for(int i = 0 ; i < 4 ; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int newEffort = max(abs(heights[nrow][ncol]-heights[row][col]),step);
                    if(newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = newEffort;
                        qp.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
