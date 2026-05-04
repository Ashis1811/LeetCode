class Solution {
public:
    int solve(vector<int>& arr, int maxSum, int k)
    {
        int subarray = 1, sum = 0;
        for(auto curr : arr)
        {
            if(curr + sum > maxSum)
            {
                subarray++;
                sum = curr;
            }
            else
            {
                sum += curr;
            }
        }
        return subarray <= k;
    }
    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        if(k > arr.size()) return -1;
        int ans = high;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(solve(arr, mid, k))
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