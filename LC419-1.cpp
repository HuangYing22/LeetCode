/* Given an 2D board, count how many battleships are in it. 
The battleships are represented with 'X's, empty slots are represented with '.'s. 

You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. 
In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), 
where N can be of any size.

At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.

Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.

Follow up:
Could you do it in one-pass, 
using only O(1) extra memory and without modifying the value of the board? */

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        int nRow = board.size();
        int nCol = board[0].size();
        vector<bool> pRow(nCol, false);
        int res = 0;
        
        for(int i = 0; i < nRow; i ++) {
            for(int j = 0; j < nCol; j ++) {
                if((board[i][j] == 'X') && !pRow[j]) { 
                    pRow[j] = true;
                    if(((j > 0) && (board[i][j - 1] != 'X')) || (j == 0)) {
                        res ++;
                    }
                } else if((board[i][j] == '.')) {
                    pRow[j] = false;
                }
            }
        }
        
        return res;
        
    }
};
