class Solution {
public:
    int divisor(vector<int>& nums, int threshold)
    {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += ceil((double)nums[i] / (double)threshold);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());
        if(n > threshold) return -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(divisor(nums, mid) > threshold)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};