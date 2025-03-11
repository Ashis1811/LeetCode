class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for(int ind = n - 1; ind >= 0; ind--)
        {
            while(! st.empty() && temperatures[ind] >= temperatures[st.top()])
            {
                st.pop(); 
            }
            if(! st.empty())
            {
                ans[ind] = st.top() - ind;
            }
            st.push(ind);
        }
        return ans;
    }
};