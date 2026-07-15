class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;
        long long n = abs((long long)dividend), m = abs((long long)divisor);
        long long ans = 0;
        while(n >= m){
            int count = 0;
            while(n >= (m << (count + 1))){
                count++;
            }
            ans += 1LL << (count);
            n -= (m * (1LL << count));
        }
        if(ans > INT_MAX && sign) return INT_MAX;
        if(ans > INT_MAX && !sign) return INT_MIN;
        return sign ? ans : (-1 * ans);
    }
};