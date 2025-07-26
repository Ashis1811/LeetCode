class Solution {
public:
    int helper(vector<int>& nums, int k)
    {
        int n = nums.size();
        int left = 0, count = 0;
        unordered_map<int, int> freq;
        for(int right = 0; right < n; right++)
        {
            if(freq[nums[right]] == 0) k--;
            freq[nums[right]]++;
            while(k < 0)
            {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) k++;
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return helper(nums, k) - helper(nums, k - 1);
    }
};