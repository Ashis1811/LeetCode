
//========================= Memoization Approach ========================

// class Solution {
// public:
//     int helper(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>& dp)
//     {
//         if(ind >= n) return 0;
//         if(dp[ind][buy] != -1) return dp[ind][buy];
//         int profit = 0;
//         if(buy)
//         {
//             profit = max(- prices[ind] + helper(ind+1, 0, prices, n, dp), 0 + helper(ind+1, 1, prices, n, dp));
//         }
//         else
//         {
//             profit = max(prices[ind] + helper(ind+2, 1, prices, n, dp), 0 + helper(ind+1, 0, prices, n, dp));
//         }
//         return dp[ind][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1));
//         return helper(0, 1, prices, n, dp);
//     }
// };



//=============================== Tabulation Approach ===============================

// class Solution {
// public:

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n + 2, vector<int>(2, 0));
//         for(int ind = n - 1; ind >= 0; ind--)
//         {
//             for(int buy = 0; buy <= 1; buy++)
//             {
//                 int profit = 0;
//                 if(buy)
//                 {
//                     profit = max(- prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
//                 }
//                 else
//                 {
//                     profit = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
//                 }
//                 dp[ind][buy] = profit;
//             }
//         }
//         return dp[0][1];
//     }
// };


//================================ Space Optimization ==========================

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        vector<int> prev(2, 0), curr(2, 0), next(2, 0);
        
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    curr[buy] = max(-prices[ind] + prev[0], prev[1]);
                } else {
                    curr[buy] = max(prices[ind] + next[1], prev[0]);  
                }
            }
            next = prev;
            prev = curr;
        }
        
        return prev[1];
    }
};
