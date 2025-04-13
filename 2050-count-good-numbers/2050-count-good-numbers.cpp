class Solution {
public:
    const int mod = 1e9 + 7;
    int findPow(long long a, long long b)
    {
        if(b == 0)
        {
            return 1;
        }
        long long half = findPow(a, b/2);
        long long ans = (half * half) % mod;
        if(b % 2 == 1)
        {
            ans = (ans * a) % mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        return (long long) findPow(5, (n + 1) / 2) * findPow(4, n / 2) % mod;
    }
};