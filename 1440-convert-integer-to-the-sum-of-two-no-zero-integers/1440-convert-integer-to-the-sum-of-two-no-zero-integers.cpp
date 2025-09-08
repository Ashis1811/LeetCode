class Solution {
public:
    bool check(int n)
    {
        string str = to_string(n);
        return str.find('0') != string :: npos;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++)
        {
            int left = i;
            int right = n - i;
            if(! check(left) && ! check(right))
            {
                return {left, right};
            }
        }
        return {-1, -1};
    }
};