class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap;
        //int n = stones.size();
        for(auto it : stones)
        {
            maxHeap.push(it);
        }
        while(maxHeap.size() > 1)
        {
            int op1 = maxHeap.top();
            maxHeap.pop();
            int op2 = maxHeap.top();
            maxHeap.pop();
            if(op1 != op2)
            {
                maxHeap.push(op1 - op2);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};