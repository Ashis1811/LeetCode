

//============================== Memorization Approach ======================================
class Solution {
public:
    int helper(int amount, vector<int>& coins, vector<int>& dp)
    {
        if(amount == 0) return 0;
        if(amount < 0) return 1e9;
        if(dp[amount] != -1) return dp[amount];

        int mini = 1e9;
        for(auto coin : coins)
        {
            mini = min(mini, helper(amount - coin, coins, dp) + 1);
        }
        return dp[amount] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, -1);
        int result = helper(amount, coins, dp);
        return result >= 1e9 ? -1 : result;
    }
};


//========================= Tabulation Approach =============================
// class Solution {
// public:
//     int helper(int amount, vector<int>& coins, vector<int>& dp)
//     {
//         if(amount == 0) return 0;
//         if(amount < 0) return 1e9;
//         if(dp[amount] != -1) return dp[amount];

//         int mini = 1e9;
//         for(auto coin : coins)
//         {
//             mini = min(mini, helper(amount - coin, coins, dp) + 1);
//         }
//         return dp[amount] = mini;
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<int> dp(amount + 1, -1);
//         int result = helper(amount, coins, dp);
//         return result >= 1e9 ? -1 : result;
//     }
// };