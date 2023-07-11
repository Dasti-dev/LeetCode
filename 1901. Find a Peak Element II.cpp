class Solution {
private:
    bool check(vector<vector<int>> &mat , int a , int b)
    {
        int x[] = {0,-1,0,1};
        int y[] = {-1,0,1,0};
        for(int i = 0 ; i < 4 ; i++)
        {
            int newa = a + x[i];
            int newb = b + y[i];
            if(newa >= 0 && newa < mat.size() && newb >=0 && newb < mat[0].size() && mat[newa][newb] > mat[a][b])
            {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        for(int i = 0 ; i < mat.size() ; i++)
        {
            int low = 1;
            int high = mat[i].size()-2;
            vector<int> ans;

            if(mat[i].size() == 1)
            {
                if(check(mat,i,0) == true)
                {
                    return {i,0};
                }
            }
            if(mat[i][0] > mat[i][1]) 
            {
                if(check(mat,i,0) == true)
                {
                    return {i,0};
                }
            }
            if(mat[i][mat[i].size()-1] > mat[i][mat[i].size()-2]) 
            {
                if(check(mat,i,mat[i].size()-1) == true)
                {
                    int a = mat[i].size()-1;
                    return {i,a};
                }
            }

            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(check(mat,i,mid))
                {
                    return {i,mid};
                }
                else if(mat[i][mid+1] > mat[i][mid] && mat[i][mid - 1] < mat[i][mid + 1])
                {
                    low = mid+1;
                }
                
                else
                {
                    high = mid-1;
                }
            }
        }
        return {-1};
    }
};
