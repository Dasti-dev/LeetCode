// LEETCODE
// 27. Remove Element
// Easy
// beats 100 %
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
        int i = 0 ; int j = 0 ;
        while(j < nums.size())
        {
            if( nums[i] != val && nums[j] != val)
            {
                i++;j++;
            }
            else if( nums[i] == val && nums[j] == val)
            {
                j++;
            }
            else if( nums[i] == val && nums[j] != val)
            {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j++;
            }
        }
        for( int i = nums.size() - 1 ; i < nums.size() ; i-- )
        {
            if(nums[i] == val)
                nums.pop_back();
            else
                break;
        } 
        return nums.size();
    }
};
