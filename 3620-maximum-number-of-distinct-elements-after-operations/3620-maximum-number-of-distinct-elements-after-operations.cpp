class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long op = INT_MIN;
        int ans = 0;
        for(auto x : nums)
        {
            long left = x - k;
            long right = x + k;
            if(right > op)
            {
                long pick = max(op + 1, left);
                op = pick;
                ans++;
            }
        }
        return ans;
    }
};