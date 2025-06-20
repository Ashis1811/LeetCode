class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int north = 0, south = 0, east = 0, west = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            if(ch == 'N') north++;
            else if(ch == 'S') south++;
            else if(ch == 'E') east++;
            else if(ch == 'W') west++;

            int x = abs(east - west);
            int y = abs(north - south);
            int md = x + y;
            ans = max(ans, md + min(2 * k, i + 1 - md));
        }
        return ans;
    }
};