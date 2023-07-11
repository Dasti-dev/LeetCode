class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        string word = "";
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == ' ')
            {
                if(word != " " && word != "")
                {
                    vec.push_back(word);
                    word = "";
                }
            }
            else
            {
                word += s[i];
            }
        }
        if(word != " " && word != "")
        {
            vec.push_back(word);
        }
        reverse(vec.begin(),vec.end());
        string ans = "";
        for(int i = 0 ; i < vec.size() ; i++)
        {
            ans.append(vec[i]);
            if(i == vec.size() - 1 )
            continue;
            ans += " ";
        }
        return ans;
    }
};
