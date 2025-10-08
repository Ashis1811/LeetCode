class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int m = potions.size();
        sort(potions.begin(), potions.end());
        for(auto spell : spells)
        {
            long long thresold = (success + spell - 1) / spell;
            int index = lower_bound(potions.begin(), potions.end(), thresold) - potions.begin(); 
            ans.push_back(m - index);
        }
        return ans;
    }
};