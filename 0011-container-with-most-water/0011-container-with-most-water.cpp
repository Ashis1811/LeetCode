class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while(left < right)
        {
            int len = (right - left);
            int curr = min(height[left], height[right]) * len;
            max_area = max(curr, max_area);
            if(height[left] < height[right]) left++;
            else right--;
        }
        return max_area;
    }
};