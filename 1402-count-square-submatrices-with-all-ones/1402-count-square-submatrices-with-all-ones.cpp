class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(matrix[i][j] == 0) return dp[i][j] = 0;
        int top = memo(i - 1, j, matrix, dp);
        int left = memo(i, j - 1, matrix, dp);
        int diagonal = memo(i - 1, j - 1, matrix, dp);
        return dp[i][j] = min({top, left, diagonal}) + 1;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int square = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                square += memo(i, j, matrix, dp);
            }
        }
        return square;
    }
};