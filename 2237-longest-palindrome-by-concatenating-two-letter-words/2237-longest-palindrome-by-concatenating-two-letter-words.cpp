class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        for(auto word : words)
        {
            string revWord = word;
            swap(revWord[0], revWord[1]);
            if(mp[revWord] > 0)
            {
                ans += 4;
                mp[revWord]--;
            }
            else
            {
                mp[word]++;
            }
        }
        for(auto ch : mp)
        {
            string st = ch.first;
            int count = ch.second;
            if(st[0] == st[1] && count > 0)
            {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};