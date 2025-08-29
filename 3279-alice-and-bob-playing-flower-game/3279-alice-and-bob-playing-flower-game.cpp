class Solution {
public:
    #define ll long long
    long long flowerGame(int n, int m) {
        ll oddN = (n + 1) / 2;
        ll evenN = n / 2;
        ll oddM = (m + 1) / 2;
        ll evenM = m / 2;
        return oddN * evenM + evenN * oddM;
    }
};