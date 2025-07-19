class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0, right =0, maxSum = 0;
        for(int i = 0; i < k; i++)
        {
            left += cardPoints[i];
        }
        maxSum = left;
        for(int j = 0; j < k; j++)
        {
            left -= cardPoints[k - 1 - j];
            right += cardPoints[n - 1- j];
            maxSum = max(maxSum, left + right);
        }
        return maxSum;
    }
};