/* Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Note:
The input is assumed to be a 32-bit signed integer. 
Your function should return 0 when the reversed integer overflows. */

// int range: -2,147,483,648 to 2,147,483,647
class Solution {
private:
    int reversePos(int x) {
        if(x < 10) return x;
        
        long long val = x;
        long long res = 0;
        int last;
        
        while (val != 0) {
            last = val % 10;
            val = (val - last) / 10;
            res = res * 10 + last;
            if(res > INT_MAX) return 0;
        }
        return res;
    }
    
public:
    int reverse(int x) {
        if((x == INT_MAX) || (x == INT_MIN)) return 0;
        if((x < 10) && (x > -10)) return x;
        if(x > 0) return reversePos(x);
        if(x < 0) return (reversePos(0 - x)) * (-1);
    }
};
