class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> freq;
        int ans = -1;
        for(auto it : arr)
        {
            freq[it]++;
        }
        for(auto [num, count] : freq)
        {
            if(num == count)
            {
                ans = num;
            }
        }
        return ans;
    }
};