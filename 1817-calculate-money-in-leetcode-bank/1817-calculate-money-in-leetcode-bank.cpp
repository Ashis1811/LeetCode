class Solution {
public:
    int totalMoney(int n) {
        int money = 0, day = 0, start = 1;
        while(day < n)
        {
            for(int i = 0; i < 7 && day < n; i++)
            {
                money += start + i;
                day++;
            }
            start++;
        }
        return money;
    }
};