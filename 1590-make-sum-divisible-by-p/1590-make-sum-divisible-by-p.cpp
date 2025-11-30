class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long totalSum = 0;
        for(auto& num : nums)
        {
            totalSum += num;
        }
        int targetRem = totalSum % p;
        if(targetRem == 0) return 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        long currSum = 0;
        int minLength = nums.size();
        for(int i = 0; i < n; i++)
        {
            currSum += nums[i];
            int currRem = currSum % p;
            int reqRem = (currRem - targetRem + p) % p;
            if(mp.find(reqRem) != mp.end())
            {
                minLength = min(minLength, i - mp[reqRem]);
            }
            mp[currRem] = i;
        }
        return minLength == nums.size() ? -1 : minLength;
    }
};