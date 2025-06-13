class Solution {
public:
    int helper(vector<int>& nums, int diff, int p)
    {
        int count = 0, i = 1;
        while(i < nums.size())
        {
            if(nums[i] - nums[i - 1] <= diff)
            {
                i++;
                count++;
            }
            i++;
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[n - 1] - nums[0];
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            if(helper(nums, mid, p) >= p)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};