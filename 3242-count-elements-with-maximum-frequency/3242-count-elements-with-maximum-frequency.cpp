class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;
        for(auto x : nums)
        {
            mp[x]++;
            maxi = max(maxi, mp[x]);
        }
        int ans = 0;
        for(int i = 1; i <= 100; i++)
        {
            if(mp[i] == maxi)
            ans += mp[i];
        }
        return ans;
    }
};