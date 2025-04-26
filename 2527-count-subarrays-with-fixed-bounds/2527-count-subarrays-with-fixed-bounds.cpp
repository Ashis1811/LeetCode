class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minP = -1;
        int maxP = -1;
        int culprit = -1;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                culprit = i;
            }

            if (nums[i] == minK) {
                minP = i;
            }

            if (nums[i] == maxK) {
                maxP = i;
            }

            long long smaller = min(minP, maxP);
            long long temp = smaller - culprit;
            ans += (temp <= 0) ? 0 : temp;
        }

        return ans;
    }
};