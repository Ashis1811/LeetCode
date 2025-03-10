class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
        {
            return a[1] < b[1];
        }
        );
        
        int remove = 0;
        int endTime = intervals[0][1];
        for(int startTime = 1; startTime < intervals.size(); startTime++)
        {
            if(intervals[startTime][0] < endTime)
            {
                remove++;
            }
            else
            {
                endTime = intervals[startTime][1];
            }
        }
        return remove;
    }
};