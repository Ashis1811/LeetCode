class Solution {
public:
double memo(int a, int b, vector<vector<double>>& dp)
{
    if(a <= 0 && b > 0)
    {
        return 1.0;
    }
    if(a == 0 && b == 0)
    {
        return 0.5;
    }
    if(a > 0 && b <= 0)
    {
        return 0.0;
    }
    if(a <= 0 && b <= 0)
    {
        return 0.5;
    }
    if(dp[a][b] != -1) return dp[a][b];

    double p = 0.25 * memo(a - 100, b, dp);
    double q = 0.25 * memo(a - 75, b - 25, dp);
    double r = 0.25 * memo(a - 50, b - 50, dp);
    double s = 0.25 * memo(a - 25, b - 75, dp);
    return dp[a][b] = p + q + r + s;
}
    double soupServings(int n) {
        if(n >= 5000) return 1;
        vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));
        return memo(n, n, dp);
    }
};