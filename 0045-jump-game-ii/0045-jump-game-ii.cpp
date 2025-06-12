class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int move = 0, count = 0, end = 0;
         for(int i = 0; i < n - 1; i++)
         {
            move = max(move, i + nums[i]);
            if(i == end)
            {
                end = move;
                ++count;
            }
         }
        return count;
    }
};