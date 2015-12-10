class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        vector<vector<int>> rotMatrix(n,vector<int>(n,1));
        int i,j;
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                rotMatrix[i][n-1-j] = matrix[j][i];
            }
        }
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                matrix[i][j] = rotMatrix[i][j];
            }
        }
    }
};
