//LC72
//Given an integer n, return the number of trailing zeroes in n!.
//Your solution should be in logarithmic time complexity.

//Time Limit Exceeded
//Input = 1808548329
/*
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n > 0) {
            n -= 5;
            res++;
        }
        return res;
    }
};
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int pow = 0;
        int num = n;
        int five = 5;
        
        while(num > 0) {
            num /= 5;
            pow++;
        }
       
        for(int i=1; i<pow; i++) {
            res += n/five;
            five *= 5;
        }
        
        return res;
    }
};
