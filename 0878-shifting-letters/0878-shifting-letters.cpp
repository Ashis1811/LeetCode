class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        vector<int> shifting(n);
        shifting[n - 1] = shifts[n - 1] % 26;
        for(int i = n - 2; i >= 0; i--)
        {
            shifting[i] = (shifting[i + 1] + shifts[i]) % 26;
        }
        for(int i = 0; i < n; i++)
        {
            int curr = s[i] - 'a';
            int currshift = (curr + shifting[i]) % 26;
            s[i] = 'a' + currshift;
        }
        return s;
    }
};