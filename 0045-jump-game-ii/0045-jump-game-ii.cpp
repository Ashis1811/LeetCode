class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count = 0, move = 0, last = 0;
        if(n < 2) return 0;
        for(int i = 0; i < n - 1; i++)
        {
            move = max(move, i + nums[i]);
            if(i == last)
            {
                last = move;
                count++;
            }
        }
        return count;
    }
};