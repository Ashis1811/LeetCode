class Solution {
public:
    int removePair(string &s, char first, char second, int gain) {
        vector<char> stack;
        string temp;
        int points = 0;

        for (char c : s) {
            if (!stack.empty() && stack.back() == first && c == second) {
                stack.pop_back();
                points += gain;
            } else {
                stack.push_back(c);
            }
        }
        s = string(stack.begin(), stack.end());
        return points;
    }
    int maximumGain(string s, int x, int y) {
        int sum = 0;

        if (x >= y) {
            sum += removePair(s, 'a', 'b', x);
            sum += removePair(s, 'b', 'a', y);
        } else {
            sum += removePair(s, 'b', 'a', y);
            sum += removePair(s, 'a', 'b', x);
        }

        return sum;
    }
};
