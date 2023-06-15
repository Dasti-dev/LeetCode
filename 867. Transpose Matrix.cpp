class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<int> row(matrix.size(),0);
        vector<vector<int>> ans(matrix[0].size(),row);

        for(int i = 0 ; i < matrix.size() ; i++)
        {
            for(int j = 0 ; j < matrix[i].size() ; j++)
            {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};
