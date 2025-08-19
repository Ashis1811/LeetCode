class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, res = 0;

        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                count++;
                res += count;
            }
            else
            {
                count = 0;
            }
        }
        return res;
    }
};