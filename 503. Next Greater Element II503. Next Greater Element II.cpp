class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> sol(nums.size(),-1);
        stack<int> s;

        int n = nums.size();

        for(int i = 2*n - 1 ; i >= 0 ; i--)
        {
            while(s.empty() != true && nums[i%n] >= s.top())
            {
                s.pop();
            } 
            if(s.empty() == false)
            {
                sol[i%n] = s.top();
                s.push(nums[i%n]);
            }
            s.push(nums[i%n]);
        }
        return sol;
    }
};
