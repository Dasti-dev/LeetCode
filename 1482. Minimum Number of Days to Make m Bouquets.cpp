class Solution {
private:
    bool possible(vector<int> &arr , int day , int n , int k)
    {
        int cnt  = 0;
        int nofB = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(arr[i] <= day)
            {
                cnt++;
            }
            else
            {
                nofB += (cnt/k);
                cnt = 0; 
            }
        }
        nofB += (cnt/k);
        return nofB >= n;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1LL*k*1LL;
        if(val > bloomDay.size())
        return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0 ; i < bloomDay.size(); i++)
        {
            mini = min(bloomDay[i],mini);
            maxi = max(bloomDay[i],maxi);
        }
        int low = mini; 
        int high = maxi;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            if(possible(bloomDay,mid,m,k))
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};
