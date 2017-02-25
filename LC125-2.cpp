class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() <= 1) return true;
        
        // CANNOT DO:
        // int n = s.length();
        // for(int i = 0; i < n; i ++)
        // since s.length() might change
        
        for(int i = 0; i < s.length(); i ++) {
            if(isalpha(s[i])) {
                s[i] = tolower(s[i]);
            } else if(!isdigit(s[i])) {
                s.erase(s.begin() + i);
                i --;
            }
        }
        
        int m = s.length();
        for(int i = 0; i < m / 2; i ++) {
            if(s[i] != s[m - 1 - i]) return false;
        }
        return true;
    }
};
