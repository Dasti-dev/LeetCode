// LEETCODE
// 29. Divide Two Integers
// people use division , so gets beats 5.3% 
// Use bit manipulation
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int quotient = 0;
        int flag = 1;
        signed long long int up = dividend;
        signed long long int down = divisor;

        if(divisor == 1)
        {

            if(dividend<INT_MIN)
            {
                return INT_MIN;
            }
            if(dividend>INT_MAX)
            {
                return INT_MAX;
            }
            return dividend;
        }
        if(divisor == -1)
        {
            up = 0-up;

            if(up<INT_MIN)
            {
                return INT_MIN;
            }
            if(up>INT_MAX)
            {
                return INT_MAX;
            }
            return up;
        }
        
        if(up < 0 && down < 0)
        {
            up = -up;
            down = -down;
            flag = 1;
        }
        else if(up > 0 && down < 0)
        {
            down = -down;
            flag = -1;
        }
        else if(up < 0 && down > 0)
        {
            up = -up;
            flag = -1;
        }
        if(down == up)
        {
            return flag;
        }
        while(up >= down)
        {
            up = up - down;
            quotient++;
        }
        if(quotient<INT_MIN)
        {
            return INT_MIN;
        }
        if(quotient>INT_MAX)
        {
            return INT_MAX;
        }
        return flag*quotient;
    }
};
