class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> list;
        // 2-D array to 1-D array
        for(auto row : grid)
        {
            for(auto col : row)
            {
                list.push_back(col);
            }
        }
        // Check if possible to divide by x
        int remainder = list[0] % x;
        for(auto num : list)
        {
            if(num % x != remainder)
            {
                return -1;
            }
        }
        sort(list.begin(), list.end());
        int mid = list[list.size() / 2];
        int op = 0;
        for(auto num : list)
        {
            op += abs(num - mid) / x;
        }
        return op;
    }
};