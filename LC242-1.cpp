//LC242
//Given two strings s and t, write a function to determine if t is an anagram of s.
//For example,
//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.
//Note:
//You may assume the string contains only lowercase alphabets.
//What if the inputs contain unicode characters? How would you adapt your solution to such case?

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        if(s.empty() && t.empty()) return true;
        
        priority_queue<char> heap_s;
        priority_queue<char> heap_t;
        
        int ls = s.length();
        int lt = t.length();
        
        for(int i=0; i<ls; i++) {
            heap_s.push(s[i]);
        }
        
        for(int i=0; i<lt; i++) {
            heap_t.push(t[i]);
        }
        
        while(!heap_s.empty() && !heap_t.empty()) {
            char cs = heap_s.top();
            char ct = heap_t.top();
            if(cs != ct) return false;
            heap_s.pop();
            heap_t.pop();
        }
        
        return true;
    }
};
