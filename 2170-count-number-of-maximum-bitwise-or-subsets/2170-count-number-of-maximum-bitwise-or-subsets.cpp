// class Solution {
// public:
//     int countMaxOrSubsets(vector<int>& nums) {
//         int maxOr = 0;
//         int ans = 0;
//         int n  = nums.size();
//         for(int i = 0; i < n; i++)
//         {
//             maxOr |= nums[i];
//         }
//         int total = pow(2, n);
//         for(int i = 0; i < total; i++)
//         {
//             int Or = 0;
//             for(int j = 0; j < n; j++)
//             {
//                 if(i & (1 << j))
//                 {
//                     Or |= nums[j];
//                 }
//             }
//             if(Or == maxOr)
//                 {
//                     ans++;
//                 }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    void helper(vector<int>& nums, int index, int Or, int maxOr, int& count)
    {
        if(Or == maxOr)
        {
            count++;
        }
        for(int i = index; i < nums.size(); i++)
        {
            helper(nums, i + 1,  Or | nums[i], maxOr, count);
        }
    }
     int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int num : nums)
        {
            maxOr |= num;
        }
        int count = 0;
        helper(nums, 0, 0, maxOr, count);
        return count;
    }
};