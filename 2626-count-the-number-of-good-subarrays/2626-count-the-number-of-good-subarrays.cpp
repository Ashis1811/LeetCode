class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        long long pair = 0;
        long long ans = 0;
        int left = 0;
        for(int right = 0; right < n; right++)
        {
            pair += freq[nums[right]];
            freq[nums[right]]++;
            while(pair >= k)
            {
                ans += n - right;
                freq[nums[left]]--;
                pair -= freq[nums[left]];
                left++;
            }
        }
        return ans;
    }
};