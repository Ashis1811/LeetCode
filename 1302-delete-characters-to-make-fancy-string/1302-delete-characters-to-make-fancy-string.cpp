class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int count = 1;
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < n; i++)
        {
            if(s[i] == st.top())
            {
                count++;
                if(count > 2) continue;
            }
            else
            {
                count = 1;
            }
            st.push(s[i]);
        }
        string ans = "";
        while(! st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};