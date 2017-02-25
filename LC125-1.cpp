/* Given a string, determine if it is a palindrome, 
considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? 
This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. */

class Solution {
private:
    string convertToLowerCase(string s) {
        int n = s.length();
        string res = "";
        
        for(int i = 0; i < n; i ++) {
            if((s[i] >= 'A') && (s[i] <= 'Z')) {
                res.push_back(s[i] + 32);
            } else if(((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= '0') && (s[i] <= '9'))  ) {
                res.push_back(s[i]);
            } else continue;
        }
        
        return res;
    }
    
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return true;
        
        string sl = convertToLowerCase(s);
        int i = 0;
        int j = sl.size() - 1;
        
        while(i <= j) {
            if(sl[i] != sl[j]) return false;
            i ++;
            j --;
        }
        
        return true;
    }
};
