class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] != 0 || grid[m - 1][n - 1] != 0) return -1;
        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push({0, {0, 1}});
        vis[0][0] = 1;

        while(! q.empty())
        {
            int row = q.front().first;
            int col = q.front().second.first;
            int len = q.front().second.second;
            q.pop();
            if(row == m - 1 && col == n - 1) return len;
            int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
            for(int i = 0; i < 8; i++)
            {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0 && vis[nRow][nCol] == 0)
                {
                    q.push({nRow, {nCol, len + 1}});
                    vis[nRow][nCol] = 1;
                }
            }
        }
        return -1;
    }
};