class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int leftMost = 0;
        int rightMost = 0;
        int res = 0;

        while(l<=r)
        {
            if(height[l] <= height[r])
            {
                if(leftMost > height[l])
                {
                    res = res + leftMost -height[l];
                }
                else
                {
                    leftMost = height[l];
                }
                l++;
            }
            else
            {
                if(rightMost > height[r])
                {
                    res = res + rightMost - height[r];
                }
                else
                {
                    rightMost = height[r];
                }
                r--;
            }
        }
        return res;
    }
};
