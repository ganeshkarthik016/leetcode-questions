class Solution {
public:
double fastpow(double a,long long  b) {
    double ans = 1;

    while (b > 0) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }

    return ans;
}
    double myPow(double x, int n) {
        bool sign = (n > 0);
        long long p = n;
        if(p<0) p *= -1;
        double ans = fastpow(x, p);
        return (sign) ? ans : 1.0/ans;
    }
};