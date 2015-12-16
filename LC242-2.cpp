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
        
        vector<int> letterCountS(26,0);
        vector<int> letterCountT(26,0);
        int l = s.length();
        
        for(int i=0; i<l; i++) {
            int as = s[i]-'a';
            letterCountS[as]++;
            int at = t[i]-'a';
            letterCountT[at]++;
        }
        
        if(letterCountS != letterCountT) return false;
       
        return true;
    }
};
