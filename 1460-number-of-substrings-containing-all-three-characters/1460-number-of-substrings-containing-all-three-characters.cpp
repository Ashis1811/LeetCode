class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> ans(3, 0);
        int count = 0;
        int left = 0;
        for(int right = 0; right < n; right++)
        {
            ans[s[right] -'a']++;
            while(ans[0] > 0 && ans[1] > 0 && ans[2] > 0)
            {
                count += (n - right);
                ans[s[left] -'a']--;
                left++;
            }
        }
        return count;
    }
};