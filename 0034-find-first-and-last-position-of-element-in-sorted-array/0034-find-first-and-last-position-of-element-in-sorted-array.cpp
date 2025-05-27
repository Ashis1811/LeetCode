class Solution {
public:
    int solve(vector<int>& nums, int target, bool searchLeft)
    {
        int idx = -1;
        int start = 0, end = nums.size() - 1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                idx = mid;
                if(searchLeft)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int start = solve(nums, target, true);
        int end = solve(nums, target,  false);
        ans[0] = start;
        ans[1] = end;
        return ans;
    }
};