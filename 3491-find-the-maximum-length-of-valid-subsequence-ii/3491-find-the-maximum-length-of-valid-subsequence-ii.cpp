class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 1;
        for(int val = 0; val < k; val++)
        {
            vector<int> dp(k, 0);
            for(auto x : nums)
            {
                int m = x % k;
                int prev = (val - m + k) % k;
                dp[m] = max(dp[m], dp[prev] + 1);
                ans = max(ans, dp[m]);
            }
        }
        return ans;
    }
};