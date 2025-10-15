
class Solution {
public:
    bool helper(vector<int>& nums, int k, int n) {
        for (int i = 0; i + 2 * k - 1 < n; i++) {
            if (nums[i] >= k && nums[i + k] >= k) return true;
        }
        return false;
    }

    int maxIncreasingSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> digit(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                digit[i] = digit[i + 1] + 1;
            }
        }

        int left = 1;
        int right = n / 2;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (helper(digit, mid, n)) {
                result = mid;  // Update result to the current valid mid
                left = mid + 1;  // Try for a larger k
            } else {
                right = mid - 1;  // Try for a smaller k
            }
        }
        return result;
    }
};

