//LC242
//Given two strings s and t, write a function to determine if t is an anagram of s.
//For example,
//s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.
//Note:
//You may assume the string contains only lowercase alphabets.
//What if the inputs contain unicode characters? How would you adapt your solution to such case?
//string也可以直接sort
//sort(s.begin(),s.end());
//priority queue:
//一个一个给是O(logn)
//一股脑给所有的数是O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        if(s.empty() && t.empty()) return true;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) return true;
        
        return false;
    }
};
