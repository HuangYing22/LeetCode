/* Given an integer, 
write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion? */

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        return (n % 3 == 0) && isPowerOfThree(n / 3);
    }
};
