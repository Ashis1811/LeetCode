class Solution {
public:
    int dfs(int i, int j1, int j2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
    {
        //Base cases
        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n ) return -1e9;

        if(i == m - 1)
        {
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxSum = INT_MIN;
        for(int r1 = -1; r1 <= 1; r1++)
        {
            for(int r2 = -1; r2 <= 1; r2++)
            {
                int col1 = j1 + r1;
                int col2 = j2 + r2;
                if(col1 >= 0 && col1 < n && col2 >= 0 && col2 < n )
                {
                    int sum = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                    sum += dfs(i + 1, col1, col2, m, n, grid, dp);
                    maxSum = max(maxSum, sum);
                }        
            }
        }
        return dp[i][j1][j2] = maxSum;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return dfs(0, 0, n - 1, m, n, grid, dp);
    }
};