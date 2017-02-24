/* Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
] */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        for(int i = 1; i <= numRows; i ++) {
            vector<int> cur;
            cur.push_back(1);
            if(i > 1) {
                for(int j = 0; j < (i - 2); j ++) {
                    cur.push_back(res[i - 2][j] + res[i - 2][j + 1]);
                }
                cur.push_back(1);
            }
            res.push_back(cur);
        }
        
        return res;
    }
};
