
//======================== Tabulation Approach ===========================

// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         for(int i = 0; i < n; i++)
//         {
//             dp[i][i] = 1; //single character
//         }
//         for(int len = 2; len <= n; len++)
//         {
//             for(int i = 0; i <= n - len; i++)
//             {
//                 int j = i + len - 1;
//                 if(s[i] == s[j])
//                 {
//                     dp[i][j] = 2 + dp[i + 1][j - 1];
//                 }
//                 else
//                 {
//                     dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//                 }
//             }
//         }
//         return dp[0][n - 1];
//     }
// };


//========================== Space Optimization ========================
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> prev(n, 0), curr(n, 0);
        for(int i = 0; i < n; i++)
        {
            prev[i] = 1; //single character
        }
        for(int i = n - 1; i >= 0; i--)
        {
            curr[i] = 1;
            for(int j = i + 1; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    curr[j] = 2 + prev[j - 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};