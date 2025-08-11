class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power, ans;
        for(int i = 0; i < 32; i++)
        {
            if((n & (1 << i)) != 0)
            {
                power.push_back(1 << i);
            }
        }
        for(auto it : queries)
        {
            int l = it[0];
            int r = it[1];
            long product = 1;
            for(int i = l; i <= r; i++)
            {
                product = (product * power[i]) % MOD;
            }
            ans.push_back(product);
        }
        return ans;
    }
};