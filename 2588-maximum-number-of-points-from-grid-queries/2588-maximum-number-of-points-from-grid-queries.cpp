class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();
        vector<int> ans(k);
        // Sort the queries to progress increasing order
        vector<pair<int, int>> querySort;
        for(int i = 0; i < k; i++)
        {
            querySort.push_back({queries[i], i}); // {element, index}
        }
            sort(querySort.begin(), querySort.end());

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq; // {element, {row, col}}
        vector<vector<bool>> visit(m, vector<bool>(n, false));

        pq.push({grid[0][0], {0, 0}}); //push first cell value & position
        visit[0][0] = true; //mark as visited

        int max_val = 0;
        int points = 0;

        //Pushing and poping from queue
        for(auto[ele, idx] : querySort)
        {
            while(! pq.empty() && pq.top().first < ele)
            {
                auto[val, pos] = pq.top();
                pq.pop();
                points++;
                max_val = max(max_val, val);
                int r = pos.first, c = pos.second;
                for(auto[dr, dc] : directions)
                {
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && ! visit[nr][nc])
                    {
                        visit[nr][nc] = true;
                        pq.push({grid[nr][nc], {nr, nc}});
                    }
                }
            }
            ans[idx] = points;
        }
        return ans;
    }
};