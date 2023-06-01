// 4 LEETCODE
// Median of Two Sorted Arrays
// Hard problem
// Used Linked list approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // int m = nums1.size();
        // int n = nums2.size();
        vector<int> vec;
        int i=0,j=0;
        while(i<nums1.size() || j<nums2.size())
        {
            if(nums2.size() == 0)
            {
                vec = nums1;
                break;
            }
            if(nums1.size() == 0)
            {
                vec = nums2;
                break;
            }
            if(j < nums2.size() && i >= nums1.size())
            {
                vec.push_back(nums2[j]);
                j++;
            }
            else if(j >= nums2.size() && i < nums1.size())
            {
                vec.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j] && j <= nums2.size() && i <= nums1.size())
            {
                vec.push_back(nums2[j]);
                j++;
            }
            else if(nums2[j]>nums1[i] && i <= nums1.size() && j <= nums2.size())
            {
                vec.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]==nums2[j] && j <= nums2.size() && i <= nums1.size())
            {
                vec.push_back(nums1[i]);
                vec.push_back(nums2[j]);
                i++;j++;
            }
            
        }
        float median;
        if(vec.size()%2 == 0)
        {
            median = float(vec[vec.size()/2]+vec[(vec.size()/2)-1])/2;
        }
        else
        {
            int ind = (vec.size()/2);
            median = vec[ind];
        }
        return median;
    }
};
