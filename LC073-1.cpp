//LC73
//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//Did you use extra space?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?


//space O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return;
        if(matrix[0].empty()) return;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row;
        vector<int> col;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    for(int k=0; k<row.size(); k++) {
                        if(row[k] == i) continue;
                    }
                    row.push_back(i);
                    for(int k=0; k<col.size(); k++) {
                        if(col[k] == j) continue;
                    }
                    col.push_back(j);
                }
            }
        }
        
        for(int i=0; i<row.size(); i++) {
            matrix[row[i]] = vector<int> (n,0);
        }
        for(int i=0; i<col.size(); i++) {
            for(int j=0; j<m; j++) {
                matrix[j][col[i]] = 0;
            }
        }
        return;
    }
};
