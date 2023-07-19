class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int count = 0;
        while(i<j)
        {
            if(nums[i] != -1 && nums[j] != -1 && nums[i] + nums[j] == k)
            {
                count++;
                nums[i] = -1;
                nums[j] = -1;
                i++;
                j--;
            }
            else if(nums[i] != -1 && nums[j] != -1 && nums[i] + nums[j] < k)
            {
                i++;
            }
            else
            {
                j--;
            }
            
        }
        return count;
    }
};
