class Solution {
public:

    bool solve(vector<int>& row, int target)
    {
        int n = row.size();
        int low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(row[mid] == target)
            {
                return true;
            }
            else if(target > row[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++)
        {
            bool flag = solve(matrix[i], target);
            if(flag)
            {
                return true;
            }
        } 
        return false;
    }
};