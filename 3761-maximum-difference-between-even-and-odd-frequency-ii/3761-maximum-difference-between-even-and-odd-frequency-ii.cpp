class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size(), ans = INT_MIN;
        auto perms = [&]() {
            vector<pair<char,char>> v;
            for (char a='0'; a<='4'; ++a)
              for (char b='0'; b<='4'; ++b)
                if (a!=b) v.emplace_back(a,b);
            return v;
        }();

        for (auto [a, b] : perms) {
            vector<vector<int>> minDiff(2, vector<int>(2, INT_MAX/2));
            vector<int> preA(n+1), preB(n+1);
            for (int i = 0; i < n; ++i) {
                preA[i+1] = preA[i] + (s[i] == a);
                preB[i+1] = preB[i] + (s[i] == b);
            }
            int l = 0;
            for (int r = 1; r <= n; ++r) {
                // advance window start while valid
                while (r - l >= k && preA[l] < preA[r] && preB[l] < preB[r]) {
                    minDiff[preA[l] % 2][preB[l] % 2] = 
                        min(minDiff[preA[l] % 2][preB[l] % 2], preA[l] - preB[l]);
                    ++l;
                }
                int pa = preA[r] % 2, pb = preB[r] % 2;
                ans = max(ans, (preA[r] - preB[r]) - minDiff[1 - pa][pb]);
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
};
