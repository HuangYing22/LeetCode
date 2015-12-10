class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int i,j;
        vector<vector<int>> path(m,vector<int>(n,1));
        
        for (i=0;i<m;i++) {
            if(obstacleGrid[i][0] == 1) {
                for (j=i;j<m;j++) {
                    path[j][0] = 0;
                }
            }
        }
        
        //for (i=0;i<n;j++) { //time exceeded
        for (i=0;i<n;i++) { //be careful when copying
            if(obstacleGrid[0][i] == 1) {
                for (j=i;j<n;j++) {
                    path[0][j] = 0;
                }
            }
        }
        
        for (i=1;i<m;i++) {
            for (j=1;j<n;j++) {
                if (obstacleGrid[i][j] == 0) {
                    path[i][j] = path[i-1][j]+path[i][j-1];
                } else {
                    path[i][j] = 0;
                }
            }
        }
        return path[m-1][n-1];
    }
};
