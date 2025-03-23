class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n); // {u, v, w}
        for(auto it : roads)
        {
            int u = it[0], v = it[1], w = it[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> way(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dist[0] = 0;
        way[0] = 1;
        pq.push({0, 0}); // {curr_dist, node}
        while(! pq.empty())
        {
            auto [curr_dist, node] = pq.top();
            pq.pop();
            if(curr_dist > dist[node]) continue;
            for(auto [neighbor, time] : graph[node])
            {
                long long new_dist = curr_dist + time;
                if(new_dist < dist[neighbor])
                {
                    dist[neighbor] = new_dist;
                    way[neighbor] = way[node];
                    pq.push({new_dist, neighbor});
                }
                else if(new_dist == dist[neighbor])
                {
                    way[neighbor] = (way[neighbor] + way[node]) % MOD;
                }
            }
        }
        return way[n - 1];
    }
};