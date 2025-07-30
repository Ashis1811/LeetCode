class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ele = *max_element(nums.begin(), nums.end());
        int count = 0, maxCount = 0;
        for(auto num : nums)
        {
            if(num == ele)
            {
                count++;
                maxCount = max(maxCount, count);
            }
            else count = 0;
        }
        return maxCount;
    }
};