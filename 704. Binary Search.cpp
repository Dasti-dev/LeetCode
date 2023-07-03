class Solution {
private:
    int bsearch(vector<int> &nums , int target , int low , int high)
    {
        if(low<=high)
        {
            int mid = low+((high-low)/2);
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                return bsearch(nums,target,low,mid-1);
            }
            
            return bsearch(nums,target,mid+1,high);
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int sol = bsearch(nums,target,0,nums.size()-1);
        return sol;
    }
};
