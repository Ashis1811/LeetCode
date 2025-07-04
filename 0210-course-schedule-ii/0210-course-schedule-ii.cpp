class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(! q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto neighbor : adj[node])
            {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        if(ans.size() == numCourses) return ans;
        return {};
    }
};