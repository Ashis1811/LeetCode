class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int n = s.size();
        int left = 0;
        int minLen = 0;
        int maxCount = 0;
        for(int right = 0; right < n; right++)
        {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);
            while(((right - left + 1) - maxCount) > k)
            {
                count[s[left] - 'A']--;
                left++;
            }
            minLen = max(minLen, right - left + 1);
        }
        return minLen;
    }
};