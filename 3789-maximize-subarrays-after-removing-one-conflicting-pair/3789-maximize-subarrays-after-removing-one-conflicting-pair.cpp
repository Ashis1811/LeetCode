class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<int> minConflict(n + 1, INT_MAX);    
        vector<int> secondMinConflict(n + 1, INT_MAX); 
        for (const auto& pair : conflictingPairs) {
            int a = min(pair[0], pair[1]);
            int b = max(pair[0], pair[1]);

            if (minConflict[a] > b) {
                secondMinConflict[a] = minConflict[a];
                minConflict[a] = b;
            } else if (secondMinConflict[a] > b) {
                secondMinConflict[a] = b;
            }
        }

        long long total = 0;
        int bestIndex = n;              
        int secondBest = INT_MAX;    

        vector<long long> recoverable(n + 1, 0); 

        for (int i = n; i >= 1; --i) {
            if (minConflict[bestIndex] > minConflict[i]) {
                secondBest = min(secondBest, minConflict[bestIndex]);
                bestIndex = i;
            } else {
                secondBest = min(secondBest, minConflict[i]);
            }

            total += min(minConflict[bestIndex], n + 1) - i;

            recoverable[bestIndex] += 
                min(min(secondBest, secondMinConflict[bestIndex]), n + 1) - 
                min(minConflict[bestIndex], n + 1);
        }

        return total + *max_element(recoverable.begin(), recoverable.end());
    }
};
