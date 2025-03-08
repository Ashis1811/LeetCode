class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int ops = INT_MAX;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
           if(i - k >= 0 && blocks[i - k] == 'B') count--;
           if(blocks[i] == 'B') count++;
           ops = min(ops, k - count);
        }
     
        return ops;
    }
};