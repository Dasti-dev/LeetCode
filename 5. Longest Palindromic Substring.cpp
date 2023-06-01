// LEETCoDE 5th Question
// Medium 
// edge case was tough
// O(n2)
class Solution {
public:
    string longestPalindrome(string s) {
        string str = "";
        int length = 0;
        for(int i = 1 ; i < s.size() ; i++)
        {
            
                int l = i-1 , r = i;
                while(l>=0 && r < s.size() && s[l]==s[r])
                {
                    if(r-l+1>length)
                    {
                        str = s.substr(l,r-l+1);
                        length = r-l+1;
                    }
                l--;
                r++;
                }
            
            
                l = i-1 , r = i+1;
                while(l>=0 && r < s.size() && s[l]==s[r])
                {
                    if(r-l+1>length)
                    {
                        str = s.substr(l,r-l+1);
                        length = r-l+1;
                    }
                l--;
                r++;
                }
        }
        if(str.size() == 0)
            {
                str = s.substr(0,1);
            }
        return str;
    }
};
