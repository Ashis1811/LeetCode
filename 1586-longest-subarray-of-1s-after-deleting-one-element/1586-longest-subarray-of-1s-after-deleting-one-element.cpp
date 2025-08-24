class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, maxi = 0, zero = 0;
        for(int right = 0; right < n; right++)
        {
            if(nums[right] == 0)
            {
                zero++;
            }
            while(zero > 1)
            {
                if(nums[left] == 0)
                {
                    zero--;
                }
                left++;
            }
            maxi = max(right - left, maxi);
        }
        return maxi;
    }
};