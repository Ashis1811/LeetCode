class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int ans = 0; 
        for(auto ch : s)
        {
            if(st.count(ch))
            {
                ans += 2;
                st.erase(ch);
            }
            else
            {
                st.insert(ch);
            }
        }
        if(! st.empty())
        {
            ans += 1;
        }
        return ans;
    }
};