class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int count = 0;
        for(auto fruit : fruits)
        {
            for(int box = 0; box < n; box++)
            {
                if(baskets[box] >= fruit)
                {
                    baskets[box] = -1;
                    count++;
                    break;
                }
            }
        }
        return n - count;
    }
};