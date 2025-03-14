class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = *max_element(candies.begin(), candies.end());
        int candy = 0;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            long long count = 0;
            for(auto c : candies)
            {
                count += c / mid;
            }
            if(count >= k)
            {
                candy = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return candy;
    }
};