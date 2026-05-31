class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row_grid(9, vector<bool>(9, false));
        vector<vector<bool>> col_grid(9, vector<bool>(9, false));
        vector<vector<bool>> block_grid(9, vector<bool>(9, false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int num = board[i][j] - '0' - 1;
                if (row_grid[i][num] || col_grid[j][num] || block_grid[((i/ 3) * 3) + (j/3)][num]) {
                    //number already exists
                    return false;
                } else {
                    row_grid[i][num] = true;
                    col_grid[j][num] = true;
                    block_grid[((i / 3) * 3) + (j / 3)][num] = true;
                }
            }
        }
        return true;
    }
};
