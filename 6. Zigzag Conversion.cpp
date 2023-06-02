// LEETCODE
// 6. Zigzag Conversion
// Medium
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        bool flag = false;
        int j = 0;
        if(numRows == 1)
        {
            return s;
        }
        for(int i = 0 ; i < s.size() ; i++)
        {
            ans[j] += s[i];
            if(j == 0 || j == numRows-1)
            {
                flag = !flag;
            }
            if(flag)
            {
                j++;
            }
            else
            {
                j--;
            }
        }
        string zz = "";
        for(int i = 0 ; i<ans.size() ; i++)
        {
            zz = zz + ans[i];
        }
        return zz;
    }
};
