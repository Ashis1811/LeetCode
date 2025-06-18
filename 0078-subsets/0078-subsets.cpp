class Solution {
public:
    void subset(int ind, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans)
    {
        if(ind == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        subset(ind + 1, nums, curr, ans);
        curr.pop_back();
        subset(ind + 1, nums, curr, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        subset(0, nums, curr, ans);
        return ans;
    }
};