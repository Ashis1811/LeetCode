
//====================== Memorization Approach ========================

class Solution {
public:
    int helper(int amount, int ind, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(amount == 0) return 1;
        if(ind >= coins.size() || amount < 0) return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int include = helper(amount - coins[ind], ind, coins, dp);
        int exclude = helper(amount, ind + 1, coins, dp);

        return dp[ind][amount] = include + exclude;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return helper(amount, 0, coins, dp);
    }
};