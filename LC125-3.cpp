class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.length() - 1;
        
        while (begin < end) {
            while((begin < end) && (!isalpha(s[begin])) && (!isdigit(s[begin])) ) {
                begin ++;
            }
            while((begin < end) && (!isalpha(s[end])) && (!isdigit(s[end])) ) {
                end --;
            }
            if(tolower(s[begin]) != tolower(s[end])) return false;
            begin ++;
            end --;
        }
        return true;
    }
};
