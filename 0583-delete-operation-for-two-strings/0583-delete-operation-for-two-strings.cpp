class Solution {
public:
    int helper(int i, int j, string word1, string word2, vector<vector<int>>& dp)
    {
        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j])
        {
            return dp[i][j] = helper(i + 1, j + 1, word1, word2, dp);
        }
        else
        {
            int del1 = 1 + helper(i + 1, j, word1, word2, dp);
            int del2 = 1 + helper(i, j + 1, word1, word2, dp);
            return dp[i][j] = min(del1, del2);
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, word1, word2, dp);
        
    }
};