/* Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, 
return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 */

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int base = 1;
        int n = s.length();
        
        for(int i = n - 1; i >= 0; i --) {
            res += (s[i] - 'A' + 1) * base;
            base *= 26;
        }
        return res;
    }
};
