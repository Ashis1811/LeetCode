class Solution {
public:
    void helper(vector<string>& v, int n, int oc, int cc, string s)
    {
        if(oc == n && cc == n)
        {
            v.push_back(s);
        }
        if(oc < n)
        {
            helper(v, n, oc + 1, cc, s + "(");
        }
        if(cc < oc)
        {
            helper(v, n, oc, cc + 1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int oc = 0, cc = 0;
        helper(v, n, oc, cc, "");
        return v;
    }
};