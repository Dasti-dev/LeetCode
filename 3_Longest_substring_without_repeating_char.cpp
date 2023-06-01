// 3 leetcode
// 3. Longest Substring Without Repeating Characters
// Easy 
// Sliding window 
// O(n) and O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int len = 0;
        for(int i=0,j=0 ; i < s.length() ; i++)
        {
            if(m.count(s[i]) == 0)
            {
                m.insert({s[i],i});
            }
            else
            {
                if(j<=m[s[i]])
                {
                    j=m[s[i]]+1; m[s[i]] = i;
                }
                m[s[i]] = i;
            }
            len = max(len,i-j+1);
        }
        return len;
    }
};
