class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minVal = 0, maxVal = 0, curr = 0;
        for(auto diff : differences)
        {
            curr += diff;
            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);
        }
        int count = (upper - lower)- (maxVal - minVal) + 1;
        return (count > 0) ? count : 0;
    }
};