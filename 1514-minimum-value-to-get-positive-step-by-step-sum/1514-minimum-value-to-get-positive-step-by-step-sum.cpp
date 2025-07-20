class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, prefix = 0;
        for(auto num : nums)
        {
            sum += num;
            prefix = min(prefix, sum);
        }
        return 1 - prefix;
    }
};