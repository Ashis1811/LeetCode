class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0, count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            prefix += nums[i];
            if(mp.find(prefix - k) != mp.end())
            {
                count += mp[prefix - k];
            }
            mp[prefix]++;
        }
        return count;
    }
};