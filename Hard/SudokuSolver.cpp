class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool b = solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true;
        }
        if (col == 9) {
            return solve(board, row + 1, 0);
        }
        if (board[row][col] != '.') {
            return solve(board, row, col+1);
        }
        
        for (char val = '1'; val <= '9'; val++) {
            if (valid(board, row, col, val)) {
                // try placing it here
                board[row][col] = val;
                // solve recursively
                if (solve(board, row, col + 1)) {
                    return true;
                }
                // if doesn't work, backtrack
                board[row][col] = '.';
            }
        }
        
        return false;
    }
    
    bool valid(vector<vector<char>>& board, int row, int col, char val) {
        // check row & col
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val || board[i][col] == val) {
                return false;
            }
        }
        
        // check 3x3 subgrid
        int sgi = (row / 3) * 3;
        int sgj = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[sgi + i][sgj + j] == val) {
                    return false;
                }
            }
        }
        
        return true;
    }
};