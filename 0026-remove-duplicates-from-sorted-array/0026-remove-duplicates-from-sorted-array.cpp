// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         if(nums.empty()) return 0;
//         int count = 0;
//         for(int i = 1; i < n; i++)
//         {
//             if(nums[i] != nums[count])
//             {
//                 count++;
//                 nums[count] = nums[i];
//             }
//         }
//         return count + 1;
//     }
// };


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(auto x : nums)
        {
            mp[x]++;
        }
        int key = 0;
        for(auto [num, freq] : mp)
        {
            nums[key] = num;
            key++;  
        }
        return key;
    }
};