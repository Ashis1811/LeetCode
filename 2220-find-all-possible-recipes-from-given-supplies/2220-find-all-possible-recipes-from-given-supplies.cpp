class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        for(int i = 0; i < recipes.size(); i++)
        {
            for(auto it : ingredients[i])
            {
                graph[it].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string> q;
        for(auto s : supplies) q.push(s);
        unordered_set<string> set;
        while(! q.empty())
        {
            auto temp = q.front();
            q.pop();
            for(auto next : graph[temp])
            {
                if(--indegree[next] == 0)
                {
                    q.push(next);
                    set.insert(next);
                }
            }
        }
        vector<string> ans;
        for(auto i : recipes)
        {
            if(set.count(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};