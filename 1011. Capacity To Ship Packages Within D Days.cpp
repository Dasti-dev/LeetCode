class Solution {
private:
    bool possible(vector<int> weights, int days, int k)
    {
        int day = 1;
        int load = 0;
        for(int i = 0 ; i < weights.size() ; i++)
        {
            if(load + weights[i] > k)
            {
                load = weights[i];
                day++;
            }
            else
            {
                load += weights[i];
            }
        }
        if(day <= days)
        return true;
        else
        return false;
    }    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0; 
        int maxi = INT_MIN;
        for(int i = 0 ; i < weights.size() ; i++)
        {
            sum += weights[i];
            maxi = max(maxi,weights[i]);
        }
        int low = maxi;
        int high = sum;
        

        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(possible(weights,days,mid))
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
