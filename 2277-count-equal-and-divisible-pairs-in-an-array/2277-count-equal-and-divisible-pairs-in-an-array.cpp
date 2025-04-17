class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int pair = 0;
        for(int left = 0; left < n; left++)
        {
            for(int right = left + 1; right < n; right++)
            {
                if(nums[right] == nums[left] && (left * right) % k == 0)
                {
                    pair++;
                }
            }
        }
        
        return pair;
    }
};