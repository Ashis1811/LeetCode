class Solution {
    #define pi pair<int, pair<int, int>>
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // put 1st and last row in pq
        for(int i = 0; i < n; i++)
        {
            vis[0][i] = 1;
            vis[m - 1][i] = 1;
            pq.push({heightMap[0][i], {0, i}}); // {height, {row, col}}
            pq.push({heightMap[m - 1][i], {m - 1, i}});
        }
        // put 1st and last column in pq
        for(int i = 0; i < m; i++)
        {
            vis[i][0] = 1;
            vis[i][n - 1] = 1;
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
        }
        int ans = 0;
        while(! pq.empty())
        {
            int h = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            int dr[] = {-1, 0, 1, 0}; //top - left - down - right
            int dc[] = {0, -1, 0, 1};
            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && ! vis[nr][nc])
                {
                    ans += max(0, (h - heightMap[nr][nc]));
                    pq.push({max(h, heightMap[nr][nc]), {nr, nc}});
                    vis[nr][nc] = 1;                
                }
            }
        }
        return ans;
    }
};