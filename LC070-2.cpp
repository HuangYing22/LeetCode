class Solution {
public:
    int climbStairs(int n) {
        long long res[50]; //F47 > int_max
        res[0] = 1;
        res[1] = 1;
        
        for(int i = 0; i < 48; i ++) 
            res[i + 2] = res[i] + res[i + 1];
            
        return res[n];
    }
};
