class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n < 3)
            return false; // check if consecutive numbers less than three
        for (int i = 0; i <= n - 3; i++) {
            if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0) {
                return true;
            }
        }
        return false;
    }
};