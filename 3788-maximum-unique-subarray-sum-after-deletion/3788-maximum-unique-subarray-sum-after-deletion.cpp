class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int maxSum = INT_MIN;
        for(int right = 0; right < nums.size(); right++)
        {
            if(nums[right] > 0)
            {
                st.insert(nums[right]);
            }
            else
            {
                maxSum = max(maxSum, nums[right]);
            }
        }
        int sum = 0;
        for(auto x : st)
        {
            sum += x;
        }
        if(st.size()) return sum;
        return maxSum;
    }
};