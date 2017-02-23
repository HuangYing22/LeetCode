/* The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. */

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string res_prev = countAndSay(n - 1);
        string res;
        
        int len = res_prev.length();
        char num = res_prev[0];
        int count = 1;
        
        for(int i = 1; i < len; i ++) {
            if(res_prev[i] == num) {
                count ++;
            } else {
                res.push_back(count + '0');
                res.push_back(num);
                num = res_prev[i];
                count = 1;
            }
        }
        res.push_back(count + '0');
        res.push_back(num);
        
        return res;
    }
};
