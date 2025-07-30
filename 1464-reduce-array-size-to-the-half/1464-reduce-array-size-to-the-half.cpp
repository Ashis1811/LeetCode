class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto it : arr)
        {
            mp[it]++; // store {num, freq}
        }
        priority_queue<int, vector<int>> maxHeap;
        for(auto [num, freq] : mp)
        {
            maxHeap.push(freq);
        }
        int curr = 0, size = 0;
        int n = arr.size() / 2;
        while(curr < n)
        {
            curr += maxHeap.top();
            maxHeap.pop();
            size++;
        }
        return size;
    }
};