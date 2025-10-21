class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int size = maxNum + k + 2;

        vector<int> freq(size, 0);
        for (int num : nums) {
            freq[num] += 1;
        }

        vector<int> prefixSum(size, 0);
        prefixSum[0] = freq[0];
        for (int i = 1; i < size; ++i) {
            prefixSum[i] = prefixSum[i - 1] + freq[i];
        }

        int maxFreq = 0;
        for (int target = 0; target < size; ++target) {
            if (freq[target] == 0 && numOperations == 0) {
                continue;
            }

            int start = max(0, target - k);
            int end = min(size - 1, target + k);
            int rangeFreq = prefixSum[end] - (start ? prefixSum[start - 1] : 0);
            int adjustableCount = rangeFreq - freq[target];

            int totalFreq = freq[target] + min(numOperations, adjustableCount);
            maxFreq = max(maxFreq, totalFreq);
        }

        return maxFreq;
    }
};
