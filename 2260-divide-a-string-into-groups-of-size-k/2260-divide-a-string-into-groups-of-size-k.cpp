class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        string group = "";
        for(char c : s)
        {
            group += c;
            if(group.size() == k)
            {
                ans.push_back(group);
                group.clear();
            }
        }
        if(! group.empty())
        {
            while(group.size() < k)
            {
                group += fill;
            }
            ans.push_back(group);
        }
        return ans;
    }
};