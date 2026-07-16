class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n == 0) return 1.0;
        if(x == 0) return 0.0;
        if(x == 1) return x;
        if(x == -1 && n%2 == 0) return 1.0;
        if(x == -1 && n%2 != 0) return -1.0;

        if(N < 0) {
            x = 1/x;
            N = -N;
        }

        double ans = 1;

        while(N > 0) {
            if(N % 2 == 1) {
                ans *= x;
                N -= 1;
            }
            else {
                x *= x;
                N /= 2;
            }
        }
        return ans;
    }
};