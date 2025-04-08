class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mp; 
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                return i / 3 + 1;
            }
            mp[nums[i]]++;
        }

        return 0;

    }
};