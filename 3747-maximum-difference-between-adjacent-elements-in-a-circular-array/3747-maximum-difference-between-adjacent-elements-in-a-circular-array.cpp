class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxi = abs(nums[0] - nums[n - 1]);
        if(n < 2) return 0;
        for(int i = 0; i < n - 1; i++)
        {
            int diff = abs(nums[i + 1] - nums[i]);
            maxi = max(maxi, diff);
        }
        return maxi;
    }
};