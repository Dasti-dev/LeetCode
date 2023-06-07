// LEETCODE
// 34. Find First and Last Position of Element in Sorted Array
// use binary search rest is same
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int flag = 0; 
        if(nums.size() == 0)
        {
            return {-1,-1};
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == target)
            {
                v.push_back(i);
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            return {-1,-1};
        }
        for(int i = nums.size()-1 ; i >= 0 ; i--)
        {
            if(nums[i] == target)
            {
                v.push_back(i);
                break;
            }
        }
        return v;
    }
};
