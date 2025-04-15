class Solution {
public:
    int rob(int ind, int end, vector<int>& nums, vector<int>& dp)
    {
        if(ind > end) return 0;
        if(dp[ind] != -1) return dp[ind];
        int take = nums[ind] + rob(ind + 2, end, nums, dp);
        int nontake = rob(ind + 1, end, nums, dp);
        return dp[ind] = max(take, nontake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n + 1, -1), dp2(n + 1, -1);
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int op1 = rob(0, n - 2, nums, dp1);
        int op2 = rob(1, n - 1, nums, dp2);
        return max(op1, op2);
    }
};
