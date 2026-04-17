class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return;
        int i = 0, j = 0;
        int temp;
        while(j < n)
        {
            if(nums[j] == 0) j++;
            else
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j++;
            }
        }
    }
};