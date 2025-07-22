class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st; 
        int left = 0, right = 0, sum = 0, maxSum = 0;
        while(right < nums.size())
        {
            while(st.count(nums[right]))
            {
                sum -= nums[left];
                st.erase(nums[left]);
                left++;
            }
            st.insert(nums[right]);
            sum += nums[right];
            maxSum = max(maxSum, sum);
            right++;
        }
        return maxSum;
    }
};