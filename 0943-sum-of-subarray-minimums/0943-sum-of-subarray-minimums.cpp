class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        long long sum = 0;
        vector<int> left(n), right(n);
        stack<int> st;
        for(int i = 0; i < n; i++)
        {
            while(! st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(! st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--)
        {
            while(! st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            right[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++)
        {
            sum = (sum + (long long) arr[i] * (i - left[i]) * (right[i] - i)) % mod;
        }
        return sum;
    }
};