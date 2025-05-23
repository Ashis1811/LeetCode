class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<long long> dp = {0, LLONG_MIN};
        for(auto num : nums)
        {
            vector<long long> step = {dp[0] + num, dp[1] + num};
            step[0] = max(step[0], dp[1] + (num ^ k));
            step[1] = max(step[1], dp[0] + (num ^ k));
            dp = step;
        }
        return dp[0];
    }
};