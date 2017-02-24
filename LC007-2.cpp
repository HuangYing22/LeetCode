// No need to separate cases for positive and negative numbers
// -123 % 10 = -3
// -123 / 10 = -12
// "-" can be covered by res *= 10; res += lx % 10; lx /= 10;

// int range: -2,147,483,648 to 2,147,483,647
class Solution {
public:
    int reverse(int x) {
        long long lx = x;
        long res = 0;
        
        while(lx != 0) {
            res *= 10;
            res += lx % 10;
            lx /= 10;
            if((res > INT_MAX) || (res < INT_MIN)) return 0;
        }
        
        return res;
    }
};
