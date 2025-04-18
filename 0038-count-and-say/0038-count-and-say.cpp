class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        string st = "11";
        for(int i = 3; i <= n; i++)
        {
            string t = "";
            st = st + '&';
            int count = 1;
            for(int j = 1; j < st.size(); j++)
            {
                if(st[j] != st[j - 1])
                {
                    t = t + to_string(count);
                    t = t + st[j - 1];
                    count = 1;
                }
                else count++;
            }
            st = t;
        }
        return st;
    }
};