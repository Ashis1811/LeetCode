class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(auto num : nums)
        {
            total |= num;
        }
        return total * (1 << (n - 1));
    }
};