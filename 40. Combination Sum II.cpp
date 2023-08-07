class Solution {
private:
    void comb(vector<int> arr,int target,vector<vector<int>> &ans,int ind,int sum,vector<int> v)
    {
        if(sum == target)
        {
            ans.push_back(v);
        }

        if(sum<=target){
            for(int i = ind ; i < arr.size() ; i++)
            {
                if(i != ind && arr[i-1] == arr[i])
                continue;
                v.push_back(arr[i]);
                comb(arr,target,ans,i+1,sum+arr[i],v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans = {};
        int sum = 0;
        vector<int> v = {};
        comb(candidates,target,ans,0,sum,v);
        return ans;
    }
};
