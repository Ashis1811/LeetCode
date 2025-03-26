
//================================== Memoization Approach ===========================

// class Solution {
// public:
//     bool isPalindrome(int start, int end, string& s)
//     {
//         while(start <= end)
//         {
//             if(s[start++] != s[end--])
            
//                 return false;              
//         }
//         return true;
//     }
    
//     int f(int i, string& s, vector<int>& dp)
//     {
//         if(i == s.size()) return 0;
//         if(dp[i] != -1) return dp[i];
//         int minCost = INT_MAX;
//         for(int j = i; j < s.size(); j++)
//         {
//             if(isPalindrome(i, j, s))
//             {
//                 int cost = 1 + f(j + 1, s, dp);
//                 minCost = min(minCost, cost);
//             }
//         }
//         return dp[i] = minCost;
//     }

//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n, -1);
//         return f(0, s, dp) - 1;
//     }
// };

class Solution {
public:
    bool isPalindrome(int start, int end, string& s)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--])
            
                return false;              
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, 0);

        for(int ind = n - 1; ind >= 0; ind--)
        {
             int minCost = INT_MAX;
            for(int j = ind; j < n; j++)
            {
                if(isPalindrome(ind, j, s))
                {
                    int cost = 1 +(j + 1 < n ? dp[j + 1] : 0);
                    minCost = min(minCost, cost);
                }
            }
            dp[ind] = minCost;
        }
        return dp[0] - 1;
    }
};

