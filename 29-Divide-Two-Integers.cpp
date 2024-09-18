class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool isPos = true;
        if(dividend >= 0 && divisor < 0)    isPos = false;
        if(dividend < 0 && divisor > 0)     isPos = false;

        long n = abs(dividend), d = abs(divisor);
        long ans = 0;
        while(n >= d){
            long cnt = 0;
            while(n >= (d << (cnt + 1))){   //d << (cnt+1) == d * 2 ^ cnt+1
                cnt++;
            }
            ans += (1 << cnt);
            n = n - (d << cnt);
        }

        if(ans == (1 << 31) && isPos){
            return INT_MAX;
        }
        if(ans == (1 << 31) && !isPos){
            return INT_MIN;
        }
        return isPos ? ans : (-1 * ans);
    }
};