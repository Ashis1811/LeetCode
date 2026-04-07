class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto x : nums)
        {
            mp[x]++;
        }
        int ans = 0;
        for(auto [num, freq] : mp)
        {
            if(freq > n / 2)
            {
                ans = num;
            }
        }
        return ans;
    }
};