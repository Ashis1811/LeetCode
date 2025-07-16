class Solution {
public:
    int helper(vector<int>& weights, int cap)
    {
        int currWt = 0;
        int days = 1;
        for(auto wt : weights)
        {
            if(wt + currWt > cap)
            {
                days++;
                currWt = 0;
            }
            currWt += wt;
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = * max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(helper(weights, mid) <= days)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};