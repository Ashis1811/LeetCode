class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int currBuy, nextBuy, currSell, nextSell;
        nextBuy = 0, nextSell = 0;
        for(int ind = n - 1; ind >= 0; ind--)
        {
            currSell = max(prices[ind] - fee + nextBuy, 0 + nextSell);
            currBuy = max( -prices[ind] + nextSell, 0 + nextBuy);
            nextSell = currSell;
            nextBuy = currBuy;
        }
        return nextBuy;
    }
};