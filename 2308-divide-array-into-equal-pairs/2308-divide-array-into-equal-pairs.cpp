class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;  //{index, element}
        int n = nums.size();
        for(auto num : nums)
        {
            mp[num]++;
        }
        for(auto freq : mp)
        {
            if(freq.second % 2 != 0) return false;
        }
        return true;
    }
};