class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int>ans(n, 1);
        unordered_map<int, int> mp;
        set<int>dry;
        for(int i = 0; i < n; i++)
        {
            if(rains[i] == 0)
            {
                dry.insert(i);
            }
            else
            {
                int lake = rains[i];
                ans[i] = -1;
                if(mp.count(lake))
                {
                    int last = mp[lake];
                    auto it = dry.upper_bound(last);
                    if(it == dry.end())
                    {
                        return {};
                    }
                    ans[*it] = lake;
                    dry.erase(it);
                }
                mp[lake] = i;
            }
        }
        return ans;
    }
};