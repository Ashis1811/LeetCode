class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visit[0][0] = true;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(! pq.empty())
        {
            auto[ele, r, c] = pq.top();
            pq.pop();

            if(r == n - 1 && c == n - 1)
            {
                return ele;
            }
            for(auto& [dr, dc] : dir)
            {
                int nr = dr + r;
                int nc = dc + c;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visit[nr][nc])
                {
                    visit[nr][nc] = true;
                    pq.push({max(ele, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};