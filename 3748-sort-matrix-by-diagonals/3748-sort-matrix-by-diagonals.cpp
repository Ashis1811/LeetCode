class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, priority_queue<int>> maxHeaps;
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> minHeaps;
        
        // Step 1: Group elements into heaps by diagonal
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int diagonalKey = row - col;

                if (diagonalKey < 0) {
                    minHeaps[diagonalKey].push(grid[row][col]); // ascending
                } else {
                    maxHeaps[diagonalKey].push(grid[row][col]); // descending
                }
            }
        }

        // Step 2: Reconstruct the matrix with sorted diagonals
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int diagonalKey = row - col;

                if (diagonalKey < 0) {
                    grid[row][col] = minHeaps[diagonalKey].top();
                    minHeaps[diagonalKey].pop();
                } else {
                    grid[row][col] = maxHeaps[diagonalKey].top();
                    maxHeaps[diagonalKey].pop();
                }
            }
        }
        return grid;
    }
};