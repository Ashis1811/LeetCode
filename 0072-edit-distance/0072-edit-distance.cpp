class Solution {
public:
    int helper(string word1, string word2, int m, int n, vector<vector<int>>& dp)
    {
        if(m == 0) dp[m][n] = n;
        if(n == 0) dp[m][n] = m;
        if(dp[m][n] != -1) return dp[m][n];
        if(word1[m - 1] == word2[n -1])
        {
            dp[m][n] = helper(word1, word2, m - 1, n - 1, dp);
        }
        else
        {
            int insert_C = helper(word1, word2, m, n - 1, dp);
            int delete_C = helper(word1, word2, m - 1, n, dp);
            int replace_C = helper(word1, word2, m - 1, n - 1, dp);
            dp[m][n] = 1 + min({insert_C, delete_C, replace_C});
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(word1, word2, m, n, dp);
    }
};



// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size();
//         int n = word2.size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//         for(int i = 0; i <= m; i++) dp[i][0] = i;
//         for(int j = 0; j <= n; j++) dp[0][j] = j;

//         for(int i = 1; i <= m; i++)
//         {
//             for(int j = 1; j <= n; j++)
//             {
//                 if(word1[i - 1] == word2[j - 1])
//                 {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 }
//                 else
//                 {
//                     dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
//                 }
//             }
//         }
//         return dp[m][n];
//     }
// };