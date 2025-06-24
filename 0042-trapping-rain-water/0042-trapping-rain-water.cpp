class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for(int i = 1; i < n; i++)
        {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        right_max[n - 1] = height[n - 1];
        for(int j = n - 2; j >= 0; j--)
        {
            right_max[j] = max(right_max[j + 1], height[j]);
        }
        int maxi = 0;
        for(int i = 0; i < n; i++)
        {
            maxi += min(left_max[i], right_max[i]) - height[i];
        }
        return maxi;
    }
};