// LC290
// Given a pattern and a string str, find if str follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
// Notes: You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if((pattern.length() == 0) || (str.length() == 0)) return false;
        
        int pl = pattern.length();
        unordered_map<char, string> map1; //pattern to word
        unordered_map<string, char> map2; //word to pattern
        string word;
        int space;
        
        for(int i = 0; i < pl; i ++) {
            space = str.find(' ');
            if(space == -1) {
                word = str;
            } else {
                word = str.substr(0, space);
                str.erase(0, space + 1);
            }

            unordered_map<char, string>::iterator it1 = map1.find (pattern[i]);
            unordered_map<string, char>::iterator it2 = map2.find (word);
            if(it1 == map1.end()) {
                map1.insert(pair<char, string>(pattern[i], word));
            } else if(it1 -> second != word) {
                return false;
            }
            
            if(it2 == map2.end()) {
                map2.insert(pair<string, char>(word,pattern[i]));
            } else if(it2 -> second != pattern[i]) {
                return false;
            }

        }
        
        if(space != -1) return false;
        return true;
    }
};
