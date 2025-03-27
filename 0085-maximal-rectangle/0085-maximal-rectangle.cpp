class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int maxOne = 0;
        vector<int> dp(n + 1, 0);
        for(auto row : matrix)
        {
            for(int j = 0; j < n; j++)
            {
                dp[j] = (row[j] == '1') ? dp[j] + 1 : 0;
            }
                int size = dp.size();
                for(int i = 0; i < size; i++)
                {
                    int maxHeight = INT_MAX;
                    for(int j = i; j < size; j++)
                    {
                        maxHeight = min(maxHeight, dp[j]);
                        int area = maxHeight * (j - i + 1);
                        maxOne = max(maxOne, area);
                    }
                }
            }
            return maxOne;
    }
};