class Solution {
public:
    bool helper(vector<int>& ranks, int cars, long long mid)
    {
        long long totalCar = 0;
        for(auto rank : ranks)
        {
            totalCar += sqrt(mid / rank);
            if(totalCar >= cars) return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = (long long) *min_element(ranks.begin(), ranks.end()) * (long long) cars * cars;
        long long ans = 0;
        while(low <= high) 
        {
            long long mid = low + (high - low) / 2;
            if(helper(ranks, cars, mid))
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