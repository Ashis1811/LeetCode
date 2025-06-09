class Solution {
public:
    long dfs(int n, long curr, long next)
    {
        long step = 0;
        while(curr <= n)
        {
            step += min((long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return step;
    }
    int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1;
        while(k > 0)
        {
            long step = dfs(n, curr, curr + 1);
            if(step <= k)
            {
                curr += 1;
                k -= step;
            }
            else
            {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};