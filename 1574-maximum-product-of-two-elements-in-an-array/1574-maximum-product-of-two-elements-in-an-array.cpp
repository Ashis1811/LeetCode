class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>> pq;
        for(auto it : nums)
        {
            pq.push(it);
        }
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        return (first - 1) * (second - 1);
    }
};