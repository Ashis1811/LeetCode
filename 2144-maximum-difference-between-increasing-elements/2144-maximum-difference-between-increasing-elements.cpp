class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1, mini = nums[0];
        int i = 0;
        for(int j = 1; j < n; j++)
        {
            if(nums[j] > mini)
            {
                maxi = max(maxi, nums[j]- mini);
            }
            else
            {
                mini = nums[j];
            }
            
        }
        return maxi;
    }
};