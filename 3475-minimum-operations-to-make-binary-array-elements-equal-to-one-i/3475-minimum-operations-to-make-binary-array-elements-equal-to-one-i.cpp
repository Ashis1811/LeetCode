class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int op = 0;
        for(int i = 0; i <  n - 2; i++)
        {
            if(nums[i] == 0)
            {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                op++;
            }
        }
        for(auto num : nums)
        {
            if(num != 1)
            {
                return -1;
            }
        }
        return op;
    }
};