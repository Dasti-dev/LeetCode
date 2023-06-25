class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> s;
        // m[nums2[nums2.size()-1]-1] = -1;
        for(int i  = nums2.size() - 1 ; i >= 0 ; i--)
        {
            while(s.empty() != true && s.top() <= nums2[i])
            {
                s.pop();
            }
            if(s.empty() == true)
            {
                m[nums2[i]] = -1;
                s.push(nums2[i]);
            }
            else
            {
                m[nums2[i]] = s.top();
                s.push(nums2[i]);
            }
        }

        vector<int> sol;
        for(int i = 0 ; i < nums1.size() ; i++)
        {
            sol.push_back(m[nums1[i]]);
        }
        return sol; 
    }
};
