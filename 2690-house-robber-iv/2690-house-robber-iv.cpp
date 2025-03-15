class Solution {
public:
    bool helper(vector<int>& nums, int k, int capacity)
    {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= capacity)
            {
                count++;
                i++;
            }
        }
        if(count >= k) return true;
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(helper(nums, k, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};