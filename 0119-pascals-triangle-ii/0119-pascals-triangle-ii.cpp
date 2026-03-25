class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i < rowIndex + 1; i++)
        {
            vector<int> row(i + 1, 1);
            for(int j = 1; j < i; j++)
            {
                row[j] = ans[j - 1] + ans[j];
            }
            ans = row;
        }
        return ans;
    }
};