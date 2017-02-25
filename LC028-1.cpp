/* Implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

const char * strstr ( const char * str1, const char * str2 );
      char * strstr (       char * str1, const char * str2 );

Locate substring
Returns a pointer to the first occurrence of str2 in str1, 
or a null pointer if str2 is not part of str1. */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nh = haystack.length();
        int nn = needle.length();
        if(nn == 0) return 0;
        
        bool match = true;
        
        for(int i = 0; i < (nh - nn + 1); i ++) {
            if(haystack[i] != needle[0]) continue;
            match = true;
            for(int j = 0; j < nn; j ++) {
                if(haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if(match) return i;
        }
        
        return -1;
        
    }
};
