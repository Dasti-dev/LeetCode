class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int maxi = max(word1.length(),word2.length());
        string ans = "";
        for(int i = 0 ; i < maxi ; i++)
        {
            
            if(i<word1.size())ans+=word1[i];
            if(i<word2.size())ans+=word2[i];
        }
        return ans;
    }
};
