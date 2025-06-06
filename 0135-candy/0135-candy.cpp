class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);
        
            for(int i = 1; i < n; i++)
            {
                if(ratings[i] > ratings[i - 1])
                {
                    candy[i] = candy[i - 1] + 1;
                }
                //else continue;
            }
            int right = 1;
            for(int i = n - 2; i >= 0; i--)
            {
                if(ratings[i] > ratings[i + 1])
                {
                    right++;
                    candy[i] = max(candy[i], right);
                }
                else right = 1;
            }
            int total = 0;
            for(auto x : candy)
            {
                total += x;
            }
            return total;
    }
};