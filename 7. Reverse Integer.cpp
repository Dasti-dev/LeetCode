// LEETCODE
// 7. Reverse Integer
// take care of range
class Solution {
public:
    int reverse(int x) {
        int sol=0;
            while(x)
            {
                if((sol>INT_MAX/10) || (sol<INT_MIN/10))
                {
                    return 0;
                }
                sol = sol*10 + x%10;
                x=x/10;
            }
            return sol;
        }
};
