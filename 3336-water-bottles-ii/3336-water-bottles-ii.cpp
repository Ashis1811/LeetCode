class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        while(empty >= numExchange)
        {
            ans += 1;
            empty -= numExchange;
            empty++;
            numExchange++;
        }
        return ans;
    }
};