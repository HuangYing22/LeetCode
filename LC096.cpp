//LC96
//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//For example,
//Given n = 3, there are a total of 5 unique BST's.

class Solution {
public:
    int numTrees(int n) {
        vector<int> res;
        res.push_back(1);
        
        for(int i=1; i<=n; i++) {
            int val = 0;
            for(int j=0; j<i; j++) {
                val += res[j]*res[i-j-1];
            }
            res.push_back(val);
        }
        return res[n];
    }
};
