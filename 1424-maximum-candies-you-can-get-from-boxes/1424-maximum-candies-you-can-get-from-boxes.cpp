class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> has_key(n), has_box(n), vis(n);
        //Store keys 
         for(int i = 0; i < n; i++)
         {
            has_key[i] = (status[i] == 1);
         }
        //Store box 
        for(auto box : initialBoxes)
         {
            has_box[box] = true;
         }
        queue<int> q;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(has_key[i] && has_box[i])
            {
                q.push(i);
                vis[i] = true;
            }
        }
        while(! q.empty())
        {
            int box = q.front();
            q.pop();
            ans += candies[box];

            for(auto it : keys[box])
            {
                has_key[it] = true;
                if(! vis[it] && has_box[it])
                {
                    q.push(it);
                    vis[it] = true;
                }
            }
            for(auto it : containedBoxes[box])
            {
                has_box[it] = true;
                if(! vis[it] && has_key[it])
                {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return ans;
    }
};