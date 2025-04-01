
//========================== Memoization Approach =================================

class Solution {
public:
    long long dfs(int i, vector<vector<int>>& questions, vector<long long>& dp)
    {
        if(i >= questions.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int point = questions[i][0];
        int brainpower = questions[i][1];
        int next = i + brainpower + 1;
        long long solve = point + (next < questions.size() ? dfs(next, questions, dp) : 0);
        long long skip = dfs(i + 1, questions, dp);
        return dp[i] = max(solve, skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, -1);
        return dfs(0, questions, dp);
    }
};