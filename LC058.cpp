//LC58
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//If the last word does not exist, return 0.
//Note: A word is defined as a character sequence consists of non-space characters only.

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        
        int i = s.size()-1;
        int res = 0;
        
        //deal with cases like input = "a "
        while(s[i] == ' ') {
            i--;
        }
        
        while(i >= 0) {
            if(s[i] == ' ') break;
            res++;
            i--;
        }
        
        return res;
    }
};
