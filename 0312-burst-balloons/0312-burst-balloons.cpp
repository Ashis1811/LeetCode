class Solution {
public:
    int f(int i, int j, vector<int> &arr, vector<vector<int>>& dp)
    {
        int n = arr.size();
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MIN;
        for(int k = i; k <= j; k++)
        {
            int step = arr[i - 1] * arr[k] * arr[j + 1] + f(i, k - 1, arr, dp) + f(k + 1, j, arr, dp);
            mini = max(mini, step);
        }
        return dp[i][j] = mini;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2, 1);
        for(int i = 0; i < n; i++)
        {
            arr[i + 1] = nums[i];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return f(1, n, arr, dp);
    }
};