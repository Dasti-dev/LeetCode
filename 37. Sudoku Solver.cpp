class Solution {
public:
    bool isValid(vector<vector<char>> &arr , int row , int col , char c)
    {
        for(int i = 0 ; i < 9 ; i++)
        {
            if(arr[i][col] == c)
            {
                return false;
            }
            if(arr[row][i] == c)
            {
                return false;
            }
            if(arr[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == c)
            {
                return false;
            }
        }
        return true;
    }
    bool solver(vector<vector<char>> &arr)
    {
        int n = arr[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(arr[i][j] == '.')
                {
                    for(char k = '1' ; k <= '9' ; k++)
                    {
                        if(isValid(arr,i,j,k))
                        {
                            arr[i][j] = k;
                            bool possible = solver(arr);
                            if(possible)
                            {
                                return true;
                            }
                            else
                            {
                                arr[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};
