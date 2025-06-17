class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        for(auto num : nums2)
        {
            while(! st.empty() && num > st.top())
            {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        while(! st.empty())
        {
            mp[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for(auto it : nums1)
        {
            ans.push_back(mp[it]);
        }
        return ans;
    }
};