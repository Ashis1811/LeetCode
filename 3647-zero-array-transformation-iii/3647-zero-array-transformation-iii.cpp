class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> pq;
        int n = nums.size();

        int current = 0;
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            if(i > 0)
            prefix[i] += prefix[i - 1];
            while(current < queries.size() && queries[current][0] <= i)
            {
                pq.push(queries[current][1]);
                current++;
            }
            while(prefix[i] < nums[i])
            {
                if(pq.empty() || pq.top() < i) return -1;
                prefix[i]++;
                prefix[pq.top() + 1]--;
                pq.pop();
            }
        }
        return pq.size();
    }
};