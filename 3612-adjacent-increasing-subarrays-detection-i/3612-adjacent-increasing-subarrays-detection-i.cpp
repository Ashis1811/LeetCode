class Solution {
public:
    bool helper(int start, vector<int>& nums, int k)
    {
        for(int i = start; i < start + k - 1; i++)
        {
            if(nums[i] >= nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i <= n - 2 * k; i++)
        {
            if(helper(i, nums, k) && helper(i + k, nums, k))
            {
                return true;
            }
        }
        return false;
    }
};