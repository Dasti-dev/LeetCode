class Solution {
public:
    int eating(vector<int>& piles, int k){
        int sum=0;
        for(int p: piles)
            sum+=(p+(k-1))/k; 
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long left=h-1; 
        left=accumulate(piles.begin(), piles.end(), left)/h; 
        int right=*max_element(piles.begin(),piles.end()); 
        
        while(left<right) 
        {
            int&& mid=(left+right)/2; 
            
            if (eating(piles, mid)<=h) 
                right=mid;
            else
                left=mid+1; 
        }
        
        return right; 
    }
};
