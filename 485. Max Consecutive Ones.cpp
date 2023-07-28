class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi  = 0;
        int size = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == 1)
            {
                size++;
                maxi = max(maxi,size);
            }
            else 
            {
                size = 0;
            }
        }
        return maxi;
    }
};
