class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto x : nums)
        {
            mp[x]++;
        }  
        for(auto num : mp)
        {
            if(num.second == 2)
            {
                ans.push_back(num.first);
            }
        }
        return ans;
    }
};