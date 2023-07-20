class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int res = 0;

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                count++;
            }
            
            if(i>=k)
            {
                if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u')
                {
                    count--;
                }
            }
            res  = max(res,count);
        }
        return res;
    }
};
