class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size() - 1;
        // lower bound algorithm
        // int ans = nums.size();
        // while(low <= high)
        // {
        //     int mid = low + (high-low)/2;
        //     if(nums[mid] >= target)
        //     {
        //         ans = mid;
        //         high = mid-1;
        //     }
        //     else
        //     {
        //         low = mid+1;
        //     }
        // }
        // return ans;
        // Traditional Binary search 
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return low;
    }
};
