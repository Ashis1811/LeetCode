class Solution {
public:
    int helper(vector<int>& nums, int ind, int curr_sum, int target, unordered_map<string, int>& dp)
    {
        if(ind == nums.size())
        {
            return (curr_sum == target) ? 1 : 0;
        }
        string key = to_string(ind) + "_" + to_string(curr_sum);
        if(dp.find(key) != dp.end()) return dp[key];
        int add = helper(nums, ind + 1, curr_sum + nums[ind], target, dp);
        int sub = helper(nums, ind + 1, curr_sum - nums[ind], target, dp);
        return dp[key] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return helper(nums, 0, 0, target, dp);
    }
};