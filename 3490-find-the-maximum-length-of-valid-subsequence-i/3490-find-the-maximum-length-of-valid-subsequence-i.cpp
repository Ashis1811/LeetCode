class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0;
        for(auto num : nums)
        {
            if(num % 2 == 0) even++;
            else odd++;
        }
        int dp_even = 0, dp_odd = 0;
        for(auto num : nums)
        {
            if(num % 2 == 0)
            {
                dp_even = max(dp_even, dp_odd + 1);
            }
            else
            {
                dp_odd = max(dp_odd, dp_even + 1);   
            }
        }
        return max({even, odd, dp_even, dp_odd});
    }
};