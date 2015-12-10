/*
从i/j = 0开始的话会runtime error 会access到matrix[-1]位置
与recursive的方法相比,
占内存(m x n),把exp时间变成了n^2时间

recursive方法 例如f(3,3)call f(2,3)和 f(3,2)
f(2,3) call f(1,3)和call f(2,2)
f(1,3)算出来之后马上返回给f(2,3),然后马上就释放了内存

f(23,12) = f(22,12) + f(23,11)
= f(21,12) + f(22,11) + f(22,11) + f(23,10)

f(22,11)被重复计算了=>用matrix存起来
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n,1));
        int i,j;
        for (i=1;i<m;i++) {
            for (j=1;j<n;j++) {
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    }
};
