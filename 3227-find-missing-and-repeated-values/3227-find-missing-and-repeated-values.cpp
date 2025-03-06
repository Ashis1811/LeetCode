class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int missing = -1, repeat = -1;
        unordered_map<int, int> mp;
        for(auto row : grid)
        {
            for(auto col : row)
            {
                mp[col]++;
            }
        }
        for(int i = 1; i <= m * m; i++)
        {
            if(mp[i] == 0)  missing = i;
            if(mp[i] > 1) repeat = i;
        }
        return {repeat, missing};
    }
};