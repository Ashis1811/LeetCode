class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        for(int i = 1; i < n; i++)
        {
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }
        freeTime.push_back(eventTime - endTime.back());
        int m = freeTime.size();
        vector<int> leftMax(m), rightMax(m);
        for(int i = 2; i < m; i++)
        {
            leftMax[i] = max(leftMax[i - 1], freeTime[i - 2]);
        }
        for(int i = m - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], freeTime[i + 1]);
        }
        int maxTime = 0;
        for(int i = 1; i < m; i++)
        {
            int meeting = endTime[i - 1] - startTime[i - 1];
            if(meeting <= max(leftMax[i], rightMax[i]))
            {
                maxTime = max(maxTime, freeTime[i - 1] + freeTime[i] + meeting);
            }
            maxTime = max(maxTime, freeTime[i - 1] + freeTime[i]);
        }
        return maxTime;
    }
};