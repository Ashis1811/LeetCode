class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, -1, 0, 1};
        while(! q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];
                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n)
                {
                    if(dist[nRow][nCol] > dist[row][col])
                    {
                        dist[nRow][nCol] = dist[row][col] + 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        }
        return dist;
    }
};