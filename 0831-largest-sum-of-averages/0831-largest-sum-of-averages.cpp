class Solution {
public:
    double dfs(int curr, vector<int>& nums, int k, vector<vector<double>>& dp)
    {
        if(curr >= nums.size() || k < 0) return 0;
        if(k == 0) return INT_MIN;
        if(dp[curr][k] != -1) return dp[curr][k];
        double sum = 0;
        double ans = 0;
        for(int i = curr; i < nums.size(); i++)
        {
            sum += nums[i];
            ans = max(ans, sum / (i - curr + 1) + dfs(i + 1, nums, k - 1, dp));
        }
        return dp[curr][k] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, -1));
        return dfs(0, nums, k, dp);
    }
};