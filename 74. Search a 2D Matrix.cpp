class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
        return false;
        // if(matrix.size() == 1 && matrix[0].size() == 1)
        // {
        //     if(matrix[0][0] == target)
        //     {
        //         return true;
        //     }
        //     else
        //         return false;
        // }
        // int m = matrix.size();
        // int n = matrix[0].size();
        // int low = 0;
        // int high = matrix.size() - 1;
        // while(low<=high)
        // {
        //     int mid = low + (high-low)/2;
        //     if(target >= matrix[mid][0] && target <= matrix[mid][n-1])
        //     {
        //         int lower = 0;
        //         int higher = matrix[mid].size()-1;
        //         while(lower<=higher)
        //         {
        //             int middle = lower + (higher-lower)/2;
        //             if(matrix[mid][middle] == target)
        //             {
        //                 return true;
        //             }
        //             else if(target > matrix[mid][middle])
        //             {
        //                 lower = middle+1;
        //             }
        //             else
        //             {
        //                 higher = middle-1;
        //             }
        //         }
        //     }
        //     else if(target > matrix[mid][n-1])
        //     {
        //         low = mid+1;
        //     }
        //     else 
        //     {
        //         high = mid-1;
        //     }
        // }

        // int i = 0 ;
        // int j = matrix.size() - 1;

        // while(i < matrix.size() && j >= 0)
        // {
        //     if(matrix[i][j] == target)
        //     return true;
        //     if(matrix[i][j] > target)
        //     {
        //         j--;
        //     }
        //     else
        //     {
        //         i++;
        //     }
        // }

        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = n*m-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int x = mid/m;
            int y = mid%m;
            if(matrix[x][y] == target)
            {
                return true;
            }
            else if(matrix[x][y] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return false;
    }
};
