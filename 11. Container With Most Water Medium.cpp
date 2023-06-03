// LEETCODE
// 11. Container With Most Water
// Medium
// 2 pointer approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        // maximize((i-j)*min(height[i],height[j]));
        // brute force
        // int area = 0;
        // for(int i = 0 ; i < height.size() ; i++)
        // {
        //     for(int j = i ; j < height.size() ; j++)
        //     {
        //         area = max(area,((j-i)*min(height[j],height[i])));
        //     }
        // }
        // return area;
        int i = 0 , j = height.size()-1;
        int area = 0;
        
        while(j>i)
        {
            area = max(area,(j-i)*min(height[i],height[j]));
            if(height[j]<height[i])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    return area;
    }
};
