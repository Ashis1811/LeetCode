class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, bool>> row(9), col(9), boxes(9);
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                char num = board[i][j];
                if(num == '.') continue;

                if(row[i][num]) return false;
                row[i][num] = true;

                if(col[j][num]) return false;
                col[j][num] = true;

                int boxInd = (i / 3) * 3 + (j / 3);
                if(boxes[boxInd][num]) return false;
                boxes[boxInd][num] = true;
            }
        }
        return true;
    }
};