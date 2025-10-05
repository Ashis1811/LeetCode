class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visit)
    {
        visit[i][j] = true;
        for(auto d : dir)
        {
            int x = i + d[0];
            int y = j + d[1];
            if(x < 0 || x >= m || y < 0 || y >= n) continue;
            if(visit[x][y]) continue;
            if(heights[x][y] < heights[i][j]) continue;
            dfs(x, y, heights, visit);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) dfs(i, 0, heights, pacific);
        for(int j = 0; j < n; j++) dfs(0, j, heights, pacific);

        for(int i = 0; i < m; i++) dfs(i, n - 1, heights, atlantic);
        for(int j = 0; j < n; j++) dfs(m - 1, j, heights, atlantic);

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};