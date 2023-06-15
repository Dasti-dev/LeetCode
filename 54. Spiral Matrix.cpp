class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int m = v[0].size();
        int n = v.size();
        int left = 0 ; 
        int right = m-1;
        int top = 0;
        int bottom = n-1;
    
    vector<int> sol;
    
    while( top <= bottom && right >= left )
    {
        for(int i = left ; i <= right ; i++)
        {
            sol.push_back(v[top][i]);
        }
        top++;
        for(int i = top ; i <= bottom ; i++)
        {
            sol.push_back(v[i][right]);
        }
        right--;
        if( top <= bottom ){
            for(int i = right ; i >= left ; i--)
            {
                sol.push_back(v[bottom][i]);
            }
            bottom--;
        }
        if( left <= right ){
            for(int i = bottom ; i >= top ; i--)
            {
                sol.push_back(v[i][left]);
            }
            left++;
        }
    }
    return sol;
    }
};
