class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long power = n;
        if(n < 0) power = -power;
        while(power > 0)
        {
            //For odd power
            if(power % 2 == 1)
            {
                ans *= x;
                power -= 1;
            }
            //For even power
            else
            {
                x *= x;
                power /= 2;
            }
        }
        if (n < 0) ans = (double) 1.0 / (double) ans;
        return ans;
    }
};