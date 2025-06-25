class Solution {
public:
    bool helper(vector<int>& piles, int h, int k)
    {
        long long hour = 0;
        for(auto it : piles)
        {
            hour += (it + 1LL *  k - 1) / k;
        }
        return hour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(helper(piles, h, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};