// LC 3
// Given a string, find the length of the longest substring without repeating characters. 
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
// For "bbbbb" the longest substring is "b", with the length of 1.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n <= 1) return n;
        
        bool check[256];
        memset(check, false, sizeof(check));
        
        int i = 0;
        int j = 0;
        int res = 0;
        
        while((j < n) && (i + res < n)) {
            if(!check[s[j] - NULL]) {
                check[s[j] - NULL] = true;
                j ++;
            } else {
                check[s[i] - NULL] = false;
                res = max(res, j - i);
                i ++;
            }
            
        }
        
        return max(res, j - i);
    }
};
