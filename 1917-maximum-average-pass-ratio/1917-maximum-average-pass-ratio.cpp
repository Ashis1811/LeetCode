class Solution {
    #define pi pair<double, int>
    void helper(priority_queue<pi>& maxHeap, vector<vector<int>>& classes, int idx)
    {
        double curr_avg = (double) classes[idx][0] / classes[idx][1];
        double new_avg = ((double) classes[idx][0] + 1) / (classes[idx][1] + 1);
        double increment = new_avg - curr_avg;
        maxHeap.push(make_pair(increment, idx));
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pi> maxHeap;
        for(int i = 0; i < n; i++)
            helper(maxHeap, classes, i);
        while(extraStudents--)
        {
            pi curr = maxHeap.top();
            maxHeap.pop();
            int idx = curr.second;
            classes[idx][0]++;
            classes[idx][1]++;
            helper(maxHeap, classes, idx);
        }
        double final_avg = 0.0;
        for(int i = 0; i < n; i++)
        {
            final_avg += (double)classes[i][0] / classes[i][1];
        }
        return final_avg / n;
    }
};