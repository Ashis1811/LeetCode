class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int countZero = 0;
        int maxLen = 0;
        for(int right = 0; right < n; right++)
        {
            if(nums[right] == 0)
            {
                countZero++;
            }
            while(countZero > k)
            {
                if(nums[left] == 0)
                {
                    countZero--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};