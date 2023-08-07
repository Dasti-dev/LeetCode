class Solution {
private:
    bool isPal(string s , int start , int end)
    {
        while(start<=end)
        {
            if(s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

    void part(int index , string s , vector<vector<string>> &ans , vector<string> &tmp)
    {
        if(index == s.size())
        {
            ans.push_back(tmp);
            return;
        }
        for(int i = index ; i < s.size() ; i++)
        {
            if(isPal(s,index,i))
            {
                tmp.push_back(s.substr(index,i-index+1));
                part(i+1,s,ans,tmp);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> ans;
        part(0,s,ans,tmp);
        return ans;
    }
};
