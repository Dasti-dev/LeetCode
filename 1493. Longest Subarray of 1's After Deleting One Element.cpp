class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == 0)
            {
                zero++;
            }
        }
        if(zero == 0 || zero == 1)
        {
            return nums.size()-1;
        }

        int i = 0 ;
        int j = 0 ;
        int cnt = 0;
        int ans = INT_MIN;
        while(j < nums.size())
        {
            if(nums[j] == 0)
            {
                cnt++;
            }
            while(cnt>1)
            {
                if(nums[i] == 0)
                {
                    cnt--;
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }

        return ans-1;
    }
};
