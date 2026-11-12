class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 1, longest = 1;
        if(n == 0) return 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i -1])
            {
                continue;
            }
            else if(nums[i] == nums[i - 1] + 1)
            {
                count++;
            }
            else {
                count = 1;
            }
            longest = max(longest, count);
        }
        return longest;
    }
};