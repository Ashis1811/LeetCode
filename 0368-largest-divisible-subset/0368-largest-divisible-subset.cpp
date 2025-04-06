class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxLen = 1, lastInd = 0;
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > maxLen)
            {
                maxLen = dp[i];
                lastInd = i;
            }
        }
        vector<int> ans;
        for(int i = lastInd; i != -1; i = prev[i])
        {
            ans.push_back(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};