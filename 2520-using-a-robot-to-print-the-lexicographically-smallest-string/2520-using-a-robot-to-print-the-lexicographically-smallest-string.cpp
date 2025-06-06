class Solution {
public:
    string robotWithString(string s) {
        int n = s.size(); 
        vector<char> minChar(n);
        minChar[n - 1] = s[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            minChar[i] = min(s[i], minChar[i + 1]);
        }
        stack<char> st;
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            st.push(s[i]);
            while(! st.empty() &&  (i == n - 1 || st.top() <= minChar[i + 1]))
            {
                ans += st.top();
                st.pop();
            }
        }
        while(! st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};