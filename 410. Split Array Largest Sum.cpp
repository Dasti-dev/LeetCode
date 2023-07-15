class Solution {
private:
    int numArr(vector<int> &nums , int mid)
    {
        int arr = 1;
        long long int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(sum+nums[i] <= mid)
            {
                sum += nums[i];
            }
            else
            {
                arr++;
                sum = nums[i];
            }
        }
        return arr;
    }
public:
    int splitArray(vector<int>& nums, int k) {

        if(k > nums.size()) return -1;

        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            maxi = max(maxi,nums[i]);
            sum += nums[i];
        }
        int low = maxi;
        int high = sum;
        int ans;

        while(low<=high)
        {
            int mid = (high+low)/2;
            int part = numArr(nums,mid);
            if(part <= k)
            {
                high = mid-1;
                ans  = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};
