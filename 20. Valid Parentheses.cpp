// LEETCODE
// 20. Valid Parentheses
// EASY
class Solution {
public:
    bool isValid(string s) {
        vector<char> vec;
        map<char,char> brac;
        brac[')']='(';
        brac['}']='{';
        brac[']']='[';

        for( int i = 0 ; i < s.size() ; i++ )
        {
            if ( s[i] == '(' || s[i] == '{' || s[i] == '[' )
            {
                vec.push_back(s[i]);
            }
            else if ( s[i] == ')' || s[i] == '}' || s[i] == ']' )
            {
                if(vec.size() > 0 && vec.back() == brac[s[i]])
                {
                    vec.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }

        if( vec.size()  == 0 )
        return true;
        else
        return false;
    }
};
