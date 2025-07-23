class Solution {
public:
    void helper(vector<int>& candidates, int target, int i, int currSum, vector<int>& curr, vector<vector<int>>& ans)
    {
        int n = candidates.size();
        if(currSum > target) return;
        if(currSum == target)
        {
            ans.push_back(curr);
            return;
        }
        for(int j = i; j < n; j++)
        {
            if(j > i && candidates[j] == candidates[j - 1])
            continue;
            curr.push_back(candidates[j]);
            helper(candidates, target, j + 1, currSum + candidates[j], curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, 0, curr, ans);
        return ans;

    }
};