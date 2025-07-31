class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans, prev;
        for(auto num : arr)
        {
            unordered_set<int> curr;
            curr.insert(num);
            for(auto x : prev)
            {
                curr.insert(x | num);
            }
            prev = curr;
            ans.insert(curr.begin(), curr.end());
        }
        return ans.size();
    }
};