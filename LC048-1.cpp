class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        vector<vector<int>> flipMatrix1(n,vector<int>(n,1));
        vector<vector<int>> flipMatrix2(n,vector<int>(n,1));
        int i,j;
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                flipMatrix1[j][i] = matrix[i][j];
            }
        }
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                flipMatrix2[i][j] = flipMatrix1[i][n-1-j];
            }
        }
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                matrix[i][j] = flipMatrix2[i][j];
            }
        }
    }
};
