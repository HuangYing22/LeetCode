class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        int nRow = board.size();
        int nCol = board[0].size();
        int res = 0;
        
        for(int i = 0; i < nRow; i ++) {
            for(int j = 0; j < nCol; j ++) {
                if(board[i][j] == 'X') {
                    if(i == 0) {
                        if( j == 0) {
                            res ++;
                        } else if(board[i][j - 1] == '.') {
                            res ++;
                        }
                    } else {
                        if((j == 0) && (board[i - 1][j] == '.')) {
                            res ++;
                        } else if((board[i - 1][j] == '.') && (board[i][j - 1] == '.')) {
                            res ++;
                        }
                    }
                }
            }
        }
        return res;
        
    }
};
