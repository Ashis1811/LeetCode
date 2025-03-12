class Solution {
public:
    int neg(vector<int>& nums)
    {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] < 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
    int pos(vector<int>& nums)
    {
        int low = 0, high = nums.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] > 0)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return nums.size() - low;
    }
    int maximumCount(vector<int>& nums) {
        int po = pos(nums);
        int ne = neg(nums);
        return max(po, ne);
    }
};