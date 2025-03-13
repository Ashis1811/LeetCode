class Solution {
public:
    bool helper(vector<int> nums, vector<vector<int>>& queries, int k)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < k; i++)
        {
            prefix[queries[i][0]] -= queries[i][2];
            prefix[queries[i][1] + 1] += queries[i][2];
        }
        int currSum = 0;
        for(int i = 0; i < n; i++)
        {
            currSum += prefix[i];
            nums[i] += currSum;
            if(nums[i] > 0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size();
        int ans = -1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(helper(nums, queries, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};