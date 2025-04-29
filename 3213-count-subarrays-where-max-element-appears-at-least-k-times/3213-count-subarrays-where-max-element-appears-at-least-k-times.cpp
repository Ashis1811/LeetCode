class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        //First track the max element
        int maxE = *max_element(nums.begin(), nums.end());
        int i = 0, j = 0;
        int count = 0;
        long long ans = 0;
        while (j < n) {
            if (nums[j] == maxE) {
                count++;
            }
            while (count >= k) {
                ans += n - j;
                if (nums[i] == maxE) {
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};