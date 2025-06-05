class Solution {
public:
    vector<int> parent;
    int find(int x)
    {
        if(parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void sum(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        else if(px < py) parent[py] = px;
        else parent[px] = py;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);

        for(int i = 0; i < s1.size(); i++)
        {
            sum(s1[i] - 'a', s2[i] - 'a');
        }

        string ans;
        for(auto it : baseStr)
        {
            int root = find(it - 'a');
            ans += (char) (root + 'a');
        }
        return ans;
    }
};