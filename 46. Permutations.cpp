class Solution {
public:
    void one(int ind ,vector<int> nums,vector<vector<int>>& final)
        {
            if(ind == nums.size())
            {
                final.push_back(nums);
                return;
            }
            for(int i = ind ; i < nums.size() ; i++)
            {
                swap(nums[ind],nums[i]);
                one(ind+1,nums,final);
            }
        }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> final;
        one(0,nums,final);
        return final;
    }
};
