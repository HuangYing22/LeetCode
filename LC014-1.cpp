//LC14
//Write a function to find the longest common prefix string amongst an array of strings.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n = strs.size();
        if(n == 1) return strs[0];
        
        string res = commonPrefix(strs[0], strs[1]);
        
        for(int i=2; i<n; i++) {
            res = commonPrefix(res, strs[i]);
        }
        
        return res;
    }
    
    string commonPrefix(string str1, string str2) {
        if(str1.empty() || str2.empty()) return "";
        int n1 = str1.size();
        int n2 = str2.size();
        int i = min(n1,n2);
            
        while(str1.substr(0, i) != str2.substr(0, i)) {
            i--;
        }
        if(i > 0) {
            return str1.substr(0, i);
        } else {
            return "";
        }
        
    }
};
