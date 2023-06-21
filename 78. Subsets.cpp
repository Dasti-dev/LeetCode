class Solution {
public:
    void subs (int i , vector<int> &nums , vector<int> &v , vector<vector<int>> &ans)
    {
        if( i==nums.size() )
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        subs (i+1,nums,v,ans);
        v.pop_back();
        subs (i+1,nums,v,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        subs(0,nums,v,ans);
        return ans;
    }
};
