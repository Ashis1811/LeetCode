class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        for(int pre = 0; pre < m + n - 1; pre++)
        {
            if(pre % 2 == 0)
            {
                int i = min(pre, m - 1);
                int j = pre - i;
                while(i >= 0 && j < n)
                {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }
            else
            {
                int j = min(pre, n - 1);
                int i = pre - j;
                while(j >= 0 && i < m)
                {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};