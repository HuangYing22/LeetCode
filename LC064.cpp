//一个集合如果包含一个元素(是一个空集),则这个集合本身不是空集,但它的元素是空集
//vector<vector<int>>含有空vector<int>时,vector<int>是空的,但vector<vector<int>>不是空的

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //empty condition
        //if grid is not empty, grid must have at least an element => grid[0]
        if (grid.empty() || grid[0].empty()) return 0;
        
        vector<vector<int>> minGrid = grid;
        int m = grid.size();
        int n = grid[0].size();

        int i,j;
        for (i=1;i<m;i++) {
            minGrid[i][0] += minGrid[i-1][0];
        }
        for (j=1;j<n;j++) {
            minGrid[0][j] += minGrid[0][j-1];
        }
        for (i=1;i<m;i++) {
            for (j=1;j<n;j++) {
                if(minGrid[i-1][j] < minGrid[i][j-1]) {
                    minGrid[i][j] += minGrid[i-1][j];
                } else {
                    minGrid[i][j] += minGrid[i][j-1];
                }
            }
        }
        return minGrid[m-1][n-1];
    }
};

/*
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //empty condition
        //if grid is not empty, grid must have at least an element => grid[0]
        if (grid.empty() || grid[0].empty()) return 0;
        
        vector<vector<int>> minGrid = grid;
        int m = grid.size();
        int n = grid[0].size();

        int i,j;

        for (j=1;j<n;j++) {
            minGrid[0][j] += minGrid[0][j-1];
        }
        for (i=1;i<m;i++) {
            minGrid[i][0] += minGrid[i-1][0]; //这种写法没有上一种清楚明白
            for (j=1;j<n;j++) {
                if(minGrid[i-1][j] < minGrid[i][j-1]) {
                    minGrid[i][j] += minGrid[i-1][j];
                } else {
                    minGrid[i][j] += minGrid[i][j-1];
                }
            }
        }
        return minGrid[m-1][n-1];
    }
};
*/
