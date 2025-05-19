class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        string st = "";
        if(nums[0] + nums[1] > nums[2])
        {
            if (nums[0] == nums[1] && nums[1] == nums[2])
            {
                st = "equilateral";
            }
            else if(nums[0] != nums[1] && nums[1] != nums[2] && nums[0] != nums[2])
            {
                st = "scalene";
            }
            else
            {
                st = "isosceles";
            }
        }
        else
        {
            st = "none";
        }
        return st;
    }
};