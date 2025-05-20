class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> cap(n + 1, 0);
        //Arrange the queries with left increase and right decrease
        for(auto query : queries)
        {
            int l = query[0];
            int r = query[1];
            cap[l]++;
            if(r + 1 < n)
            {
                cap[r + 1]--;
            }
        }
        //Compute prefix sum
        for(int i = 1; i < n; i++)
        {
            cap[i] += cap[i - 1];
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > cap[i])
            {
                return false;
            }
        }
        return true;
    }
};