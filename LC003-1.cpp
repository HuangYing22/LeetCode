// LC 3
// Given a string, find the length of the longest substring without repeating characters. 
// For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
// For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n <= 1) return n;
        
        int res = 1;
        int i = 0;
        while((i < n - 1) && (s[i] == s[i + 1])) {
            i ++;
        }
        if(i == n - 1) return res;
        
        map<char, bool> smap;
        int j = i;
        
        while(j < n) {
            map<char, bool>::iterator it = smap.find(s[j]);
            if(it == smap.end() || smap[s[j]] == false) {
                smap[s[j]] = true;
                j ++;
            } else {
                res = max(res, j - i);
                smap[s[i]] = false;
                i ++;
            }
        }
        
        //in case when j == n get the longest substring
        return max(res, j - i);
    }
};
