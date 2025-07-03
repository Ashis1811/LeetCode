class Solution {
public:
    char kthCharacter(int k) {
        string s1 = "a";
        while(s1.size() < k)
        {
            string s2 = "";
            for(int i = 0; i < s1.size(); i++)
            {
                s2 += s1[i] + 1;
            }
            s1 += s2;
        }
        return s1[k - 1];
    }
};