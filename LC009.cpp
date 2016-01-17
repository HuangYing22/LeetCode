// LC 9
// Determine whether an integer is a palindrome. Do this without extra space.
// Could negative integers be palindromes? (ie, -1)
// If you are thinking of converting the integer to string, note the restriction of using extra space.
// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
// There is a more generic way of solving this problem.

// INT_MAX = 2147483647
// INT_MIN = -2147483648

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        
        int copy_x = x;
        int d;
        long long reverse_x = 0;
        
        while(x > 0) {
            d = x % 10;
            reverse_x = reverse_x * 10 + d;
            x /= 10;
        }
        
        if(reverse_x > INT_MAX) return false;
        return (copy_x == reverse_x);
    }
};

// With extra space
/*
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        
        vector<int> vec;
        while(x != 0) {
            vec.push_back(x % 10);
            x /= 10;
        }
        
        int n = vec.size();
        for(int i = 0; i < n/2; i++) {
            if(vec[i] != vec[n-1-i]) return false;
        }
        
        return true;
    }
};
*/
