// LC 9
// Determine whether an integer is a palindrome. Do this without extra space.
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        
        int copy_x = x;
        int d;
        int reverse_x = 0;
        
        while(x > 0) {
            d = x % 10;
            reverse_x = reverse_x * 10 + d;
            x /= 10;
        }
        
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
