// Leetcode problem 1
// Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0 ; i < nums.size() ; i++)
        {
            int count = target - nums[i];
            for(int j = 0 ; j < nums.size() ; j++)
            {
                if (nums[j] == count)
                {
                    if (i == j)
                    continue;
                    else 
                    {
                        vector<int> vec = {i,j};

                        return vec;
                    }
                }
            }
        }
        return {0,0};
    }
};
