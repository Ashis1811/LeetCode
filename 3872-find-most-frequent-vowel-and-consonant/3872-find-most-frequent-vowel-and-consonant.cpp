class Solution {
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> mp1, mp2;
        for(auto x : s)
        {
            if(isVowel(x))
            {
                mp1[x]++;
            }
            else
            {
                mp2[x]++;
            }
        }
        int maxVowel = 0, maxConso = 0;
        for(auto p : mp1)
        {
            maxVowel = max(maxVowel, p.second);
        }
        for(auto q : mp2)
        {
            maxConso = max(maxConso, q.second);
        }

        return maxVowel + maxConso;
    }
};