
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> prefix(n), suffix(n);
        unordered_map<int, int> mp;

        int currInd = 0, last = -1;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > currInd) {
                currInd = mp[nums[i]];
                prefix[i] = {currInd, nums[i]};
                last = nums[i];
            } else {
                prefix[i] = {currInd, last};
            }
        }

        currInd = 0, last = -1;
        unordered_map<int, int> mp2;
        for (int i = n - 1; i >= 0; i--) {
            mp2[nums[i]]++;
            if (mp2[nums[i]] > currInd) {
                currInd = mp2[nums[i]];
                suffix[i] = {currInd, nums[i]};
                last = nums[i];
            } else {
                suffix[i] = {currInd, last};
            }
        }

        for (int i = 0; i < n - 1; i++) {
            int firstHalf = i + 1;
            int secondHalf = n - i - 1;

            if (prefix[i].second == suffix[i + 1].second) {
                if (prefix[i].first * 2 > firstHalf && suffix[i + 1].first * 2 > secondHalf) {
                    return i;
                }
            }
        }
        return -1;
    }
};
