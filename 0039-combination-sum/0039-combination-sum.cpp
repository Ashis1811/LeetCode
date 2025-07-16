class Solution {
public:
     void helper(vector<int>& candidates, int target, int ind, vector<int>& curr, vector<vector<int>>& ans)
     {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }
        if(target < 0 || ind >= candidates.size())
        {
            return;
        }
        curr.push_back(candidates[ind]);
        helper(candidates, target - candidates[ind], ind, curr, ans);
        curr.pop_back();
        helper(candidates, target, ind + 1, curr, ans);
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, target, 0, curr, ans);
        return ans;
    }
};