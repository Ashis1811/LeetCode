class Solution {
public:
    static bool compare(const string& a, const string& b)
    {
        return a.size() < b.size();
    }
    bool ispredecessor(string& a, string& b)
    {
        if(a.size() + 1 != b.size()) return false;
        int i = 0, j = 0;
        bool skip = false;
        while(j < b.size())
        {
            if(i < a.size() && a[i] == b[j])
            {
                i++;
            }
            else if(skip) 
            {
                return false;
            }
            else 
            {
                skip = true;
            }
            j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& nums) {
        sort(nums.begin(), nums.end(), compare);
        int n = nums.size();  
        vector<int> dp(n, 1);
        int maxLen = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(ispredecessor(nums[j], nums[i]) && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};