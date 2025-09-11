class Solution {
public:

    bool isVowel(char c)
    {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s) {
        vector<char> ans;
        for(auto c : s)
        {
            if(isVowel(c)) ans.push_back(c);
        }
        sort(ans.begin(), ans.end(), [](char a, char b)
        {
            bool upper = isupper(a);
            bool lower = isupper(b);
            if(upper != lower) return upper > lower;
            return a < b;
        });
        int n = s.size();
        int idx = 0;
        for(int i = 0; i < n; i++)
        {
            if(isVowel(s[i]))
            {
                s[i] = ans[idx++];
            }
        }
        return s;
    }
};