class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // {fraction, {index, index}}
        priority_queue<pair<double, pair<int, int>>> pq;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                double frac = arr[i] / (arr[j] * 1.0);
                if(pq.size() == k)
                {
                    if(frac < pq.top().first)
                    {
                        pq.pop();
                        pq.push({frac, {arr[i], arr[j]}});
                    }
                }
                else
                {
                    pq.push({frac, {arr[i], arr[j]}});
                }
            }
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};