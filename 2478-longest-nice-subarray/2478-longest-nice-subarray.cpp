class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int maxLen = 0;
        int curr = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            while((curr & nums[right]) != 0)
            {
                curr ^= nums[left];
                left++;
            }
            curr |= nums[right];
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};