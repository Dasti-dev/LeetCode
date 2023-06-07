// LEETCODE
// 28. Find the Index of the First Occurrence in a String
// EASY
// Boundary condition chack

class Solution {
public:
    int strStr(string haystack, string needle) {
        // if(haystack.size() == 1)
        // {
        //     if(needle.size() == 1)
        //     {
        //         if(haystack[0] == needle[0])
        //         {
        //             return 0;
        //         }
        //     }
        // }
        if(haystack.size()<needle.size())
        {
            return -1;
        }
        for(int  i = 0 ; i < haystack.size()-needle.size() + 1 ; i++)
        {
            if(haystack[i]==needle[0])
            {
                int k = i;
                int j = 0;
                while(j < needle.size())
                {
                    if(haystack[k]==needle[j])
                    {
                        j++;k++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(j==needle.size())
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
