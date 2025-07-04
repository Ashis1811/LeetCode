class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        long long len = 1;
        int currInd = 0;
        for(int i = 0; i < n; i++)
        {
            len *= 2;
            if(len >= k)
            {
                currInd = i;
                break;
            }
        }
        int shift = 0;
        for(int i = currInd; i >= 0; i--)
        {
            len /= 2;
            if(k > len)
            {
                k -= len;
                if(operations[i] == 1)
                {
                    shift++;
                }
            }
        }
        return (char) ('a' + (shift % 26));
    }
};