class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int lar = INT_MIN;

        for(int i = 0 ; i < candies.size() ; i++)
        {
            lar = max(lar,candies[i]);
        }
        vector<bool> v(candies.size());
        for(int i = 0 ; i < candies.size() ; i++)
        {
            if(candies[i] + extraCandies >= lar)
            {
                v[i] = true;
            }
            else
            {
                v[i] = false;
            }
        }
        return v;
    }
};
