
//======================== Memoization Approach ===========================

// class Solution {
// public:
//     bool solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp)
//     {
//         if(target == 0) return true;
//         if(ind == 0) return nums[0] = target;
//         if(dp[ind][target] != -1) return dp[ind][target];
//         bool nontake = solve(ind - 1, target, nums, dp);
//         bool take = false;
//         if(nums[ind] <= target)
//         {
//             take = solve(ind - 1, target - nums[ind], nums, dp);
//         }
//         return dp[ind][target] = take | nontake;
//     }
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int total = 0;
//         for(int i = 0; i < n; i++)
//         {
//             total += nums[i];
//         }
//         if(total % 2 == 1) return false;
//         else
//         {
//             int k = total / 2;
//             vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//             for(int i = 0; i < n; i++)
//             {
//                 dp[i][0] = true;
//             }
//             return solve(n - 1, k, nums, dp);
//         }
//     }
// };


//========================= Tabulation Approach ========================

class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        if(total % 2 == 1) return false;
        else
        {
            int k = total / 2;
            vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
            for(int i = 0; i < n; i++)
            {
                dp[i][0] = true;
            }
            if(nums[0] <= k)
            {
                dp[0][nums[0]] = true;
            }
            for(int ind = 1; ind < n; ind++)
            {
                for(int target = 1; target <= k; target++)
                {
                    bool nontake = dp[ind - 1][target];
                    bool take = false;
                    if(nums[ind] <= target)
                    {
                        take = dp[ind - 1][target - nums[ind]];
                    }
                    dp[ind][target] = take || nontake;
                }
                
            }
            return dp[n - 1][k];;
        }
    }
};