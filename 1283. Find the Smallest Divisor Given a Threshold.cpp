class Solution {
private:
    bool possible(vector<int> &nums , int threshold , int k)
    {
        double sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum = sum + ceil((double)(nums[i])/(double)(k));
        }
        if(sum>threshold) return false;
        else return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        int ans = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            maxi = max(nums[i],maxi);
        }
        int low = 0;
        int high  = maxi;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(possible(nums,threshold,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};
