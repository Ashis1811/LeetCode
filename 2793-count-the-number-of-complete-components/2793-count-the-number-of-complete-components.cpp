class Solution {
public:
    void dfs(int node, int& count, int& degree, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[node] = true;
        count++;
        degree += graph[node].size();

        for (auto v : graph[node]) {
            if (!vis[v]) {
                dfs(v, count, degree, graph, vis);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int count = 0, degree = 0;
            dfs(i, count, degree, graph, vis);

            if (degree == count * (count - 1)) {
                ans++;
            }
        }

        return ans;
    }
};
