class Solution {
public:
    int helper(vector<int>& nums, int k)
    {
        int n = nums.size();
        int l = 0;
        int count = 0, odd = 0;
        for(int r = 0; r < n; r++)
        {
            if(nums[r] % 2 == 1)
            {
                odd++;
            }
            while(odd > k)
            {
                if(nums[l] % 2 == 1)
                {
                    odd--;
                }
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};