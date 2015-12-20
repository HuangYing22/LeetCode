//LC73
//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//Did you use extra space?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?


//**正解space O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        if(matrix[0].empty()) return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        bool col0 = false; // if col0 should be all 0
        bool row0 = false; // if row0 should be all 0
        
        for(int i=0; i<m; i++) {
            if(matrix[i][0] == 0) { //search col[0]
                col0 = true;
                break;
            }
        }
        
        for(int j=0; j<n; j++) {
            if(matrix[0][j] == 0) { //search row[0]
                row0 = true;
                break;
            }
        }
        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0; //use col[0] and row[0] to mark all 0s
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i=1; i<m; i++) {
            if(matrix[i][0] == 0) { //set rows that should be all 0
                for(int j=1; j<n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int j=1; j<n; j++) {
            if(matrix[0][j] == 0) { //set cols that should be all 0
                for(int i=1; i<m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(col0) { //set col[0] if it should be all 0
            for(int i=0; i<m; i++) {
                matrix[i][0] = 0;
            }
        }
        
        if(row0) { //set row[0] if it should be all 0
            for(int j=0; j<n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        return;
    }
};
