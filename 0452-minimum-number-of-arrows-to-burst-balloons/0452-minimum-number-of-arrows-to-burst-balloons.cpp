class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b)
        {
            return a[1] < b[1];
        }
        );
        
        int arrow = 1;
        int endTime = points[0][1]; //First arrow position at end position of first eange
        for(int startTime = 1; startTime < points.size(); startTime++)
        {
            if(points[startTime][0] > endTime)
            {
                arrow++;
                endTime = points[startTime][1];
            }
        }
        return arrow;
    }
};

