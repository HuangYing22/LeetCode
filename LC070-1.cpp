// Time Limit Exceeded
/*
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        
        vector<int> res;
        res.push_back(1);
        res.push_back(1);
        
        for(int i = 0; i < (n - 1); i++) {
            res.push_back(res[i] + res[i + 1]);
        }
        
        return res[n];
    }
};
