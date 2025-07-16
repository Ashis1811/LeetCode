class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(int i = 0; i < m; i++)
        {
            int one = accumulate(mat[i].begin(), mat[i].end(), 0);
            pq.push({one, i});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int> ans(k, 0);
        for(int i = k - 1; i >= 0; i--)
        {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};