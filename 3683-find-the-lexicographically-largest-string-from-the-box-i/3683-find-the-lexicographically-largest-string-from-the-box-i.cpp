class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int len = n - numFriends + 1;
        string ans = "";
        if(numFriends == 1) return word;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, word.substr(i, len));
        }
        return ans;
    }
};