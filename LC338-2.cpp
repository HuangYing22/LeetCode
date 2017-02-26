/* Hint:

You should make use of what you have produced already.
Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
Or does the odd/even status of the number help you in calculating the number of 1s? */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        int flag = 2;
        
        for(int i = 1; i <= num; i ++) {
            if(i >= flag) {
                flag *= 2;
            }
            res.push_back(res[i - flag / 2] + 1);
        }
        
        return res;
    }
};
