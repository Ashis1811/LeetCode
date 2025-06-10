class Solution {
public:
    int maxDifference(string s) {
        int odd = INT_MIN, even = INT_MAX;
        vector<int> freq(26, 0);
        for(auto ch : s)
        {
            freq[ch - 'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] == 0) continue;
            else if(freq[i] & 1)
            {
                odd = max(odd, freq[i]);
            }
            else
            {
                even = min(even, freq[i]);
            }
        }
        return odd - even;
    }
};