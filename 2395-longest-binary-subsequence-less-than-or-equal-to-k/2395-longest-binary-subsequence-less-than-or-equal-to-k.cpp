class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        int n = s.size();
        long long val = 0;
        int power = 0;
        for (char ch : s)
            if (ch == '0') count++;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (power < 32) { // prevent overflow
                    val += (1LL << power); // equivalent to pow(2, power)
                    if (val <= k) {
                        count++;
                    } else {
                        break;
                    }
                }
                power++;
            } else {
                power++;
            }
        }
        return count;
    }
};
