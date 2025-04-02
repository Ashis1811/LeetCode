class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxi = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int k = n - 1; k >= 0; k--)
            {
                int j = i + 1;
                while(j < k)
                {
                    maxi = max(maxi, (long)(nums[i] - nums[j]) * nums[k]);
                    j++;
                }
            }
        }
        return (maxi < 0) ? 0 : maxi;
    }
};