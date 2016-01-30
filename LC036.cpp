// LC36
// Determine if a Sudoku is valid:
// 1. Each row must have the numbers 1-9 occuring just once.
// 2. Each column must have the numbers 1-9 occuring just once.
// 3. The numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if((board.size() < 9) || board[0].size() < 9) return false;
        
        vector<int> tag (10, 0);
        
        //Check rows
        for(int i = 0; i < 9; i ++) {
            resetTag(tag);
            for(int j = 0; j < 9; j ++) {
                if(board[i][j] == '.') continue;
                if(tag[board[i][j] - '0']) return false;
                tag[board[i][j] - '0'] = 1;
            }
        }
        
        //Check columns
        for(int j = 0; j < 9; j ++) {
            resetTag(tag);
            for(int i = 0; i < 9; i ++) {
                if(board[i][j] == '.') continue;
                if(tag[board[i][j] - '0']) return false;
                tag[board[i][j] - '0'] = 1;
            }
        }
        
        //Check 9 sub-boxes
        for(int i = 0; i < 9; i = i + 3) {
            for(int j = 0; j < 9; j = j + 3) {
                resetTag(tag);
                for(int m = i; m < i + 3; m ++) {
                    for(int n = j; n < j + 3; n ++) {
                        if(board[m][n] == '.') continue;
                        if(tag[board[m][n] - '0']) return false;
                        tag[board[m][n] - '0'] = 1;
                    }
                }
            }
        }
        
        return true;
    }
    
    void resetTag(vector<int>& tag) {
        for(int i = 0; i < 10; i ++) {
            if(tag[i] == 1) {
                tag[i] = 0;
            }
        }
        return;
    }

};
