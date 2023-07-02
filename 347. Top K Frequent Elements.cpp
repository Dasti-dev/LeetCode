class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> ump;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            ump[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : ump)
        {
            pq.push({it.second,it.first});
        }
        vector<int> sol;
        for(int i = 0 ; i < k ; i++)
        {
            sol.push_back(pq.top().second);
            pq.pop();
        }
        return sol;
        // bucket sort is optimal
    }
};
