class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; // sort by end day
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), cmp);

        // Extract end times for binary search
        vector<int> endTimes(n);
        for (int i = 0; i < n; ++i)
            endTimes[i] = events[i][1];

        // dp[i][j] = max value considering first i events, attending j events
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0];
            int value = events[i - 1][2];

            // Find last event that ends before current starts
            int prev = upper_bound(endTimes.begin(), endTimes.end(), start - 1) - endTimes.begin();

            for (int j = 1; j <= k; ++j) {
                // Skip event i
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + value);
            }
        }

        return dp[n][k];
    }
};
