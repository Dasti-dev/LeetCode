class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // BRUTE FORCE SOLUTION
        // O(n^3)
        // int longest = INT_MIN;
        // for(int i = 0 ; i < nums.size() ; i++)
        // {
        //     int len = 1;
        //     int ele = nums[i];
        //     for(int j = 0 ; j < nums.size() ; j++)
        //     {
        //         if(nums[j] == ele+1)
        //         {
        //             len++;
        //             ele = ele+1;
        //             j=0;
        //         }
        //     }
        //     longest = max(longest,len);
        // }
        // return longest;
        // ----------------------------------------------------------------------------
        // BETTER SOLUTION
        // O(nlogn + n)
        // sort(nums.begin(),nums.end());
        // int cur = 0;
        // int length = 1;
        // int last = INT_MIN;
        // for(int i = 0 ; i < nums.size() ; i++)
        // {
        //     if(nums[i]-1 == last)
        //     {
        //         last = nums[i];
        //         cur++;
        //     }
        //     else if(nums[i] != last)
        //     {
        //         last = nums[i];
        //         cur = 1;
        //     }
        //     length = max(length,cur);
        // }
        // return length;
        // ----------------------------------------------------------------------------
        // OPTIMAL BUT USES SET HEANCE HAVE SPACE COMPLEXITY of O(n)
        // O(n + 2n)
        unordered_set<int> s;
        if(nums.size() == 0)
        {
            return 0;
        }
        int longest = 1;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            s.insert(nums[i]);
        }
        for(auto it : s)
        {
            if(s.find(it-1) == s.end())
            {
                int cnt = 1;
                int x = it;
                while(s.find(x+1) != s.end())
                {
                    x = x+1;
                    cnt++;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
