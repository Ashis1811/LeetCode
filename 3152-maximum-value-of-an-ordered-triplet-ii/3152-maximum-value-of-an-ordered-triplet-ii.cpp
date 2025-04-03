class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], nums[i]);
        }
        long long ans = 0;
        int maxEle = nums[n - 1];
        for(int j = n - 2; j > 0; j--)
        {
            maxEle = max(nums[j + 1], maxEle);
            if(prefix[j - 1] > nums[j])
            {
                ans = max(ans, (long long)(prefix[j - 1] - nums[j]) * maxEle);
            }
        }
        return ans;
    }
};