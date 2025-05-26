class Solution {
public:
    int dfs(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(j < 0 || j >= n) return 1e9;
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int left = dfs(i - 1, j - 1, n, matrix, dp);
        int mid = dfs(i - 1, j, n, matrix, dp);
        int right = dfs(i - 1, j + 1, n, matrix, dp);
        return dp[i][j] = matrix[i][j] + min(left, min(mid, right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        int sum = INT_MAX;
        for(int j = 0; j < n; j++)
        {
            sum = min(sum, dfs(m- 1, j, n, matrix, dp));
        }
        return sum;
    }
};