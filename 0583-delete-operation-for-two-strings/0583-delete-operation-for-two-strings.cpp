
//========================= Tabulation Approach ======================

// class Solution {
// public:
//     int helper(string word1, string word2)
//     {
//         int m = word1.size();
//         int n = word2.size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//         for(int i = 0; i <= m; i++)
//         {
//             dp[i][0] = 0;
//         }
//         for(int j = 0; j <= n; j++)
//         {
//             dp[0][j] = 0;
//         }
//         for(int i = 1; i <= m; i++)
//         {
//             for(int j = 1; j <= n; j++)
//             {
//                 if(word1[i - 1] == word2[j - 1])
//                 {
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 }
//                 else
//                 {
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                 }
//             }
//         }
//         return dp[m][n];
//     }
//     int minDistance(string word1, string word2) {
//         int m = word1.size();
//         int n = word2.size();
//        int k = helper(word1, word2);
//        return (m - k) + (n - k);
//     }
// };


//========================= Space Optimization ======================
class Solution {
public:
    int helper(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
       int k = helper(word1, word2);
       return (m - k) + (n - k);
    }
};