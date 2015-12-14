//LC14
//Write a function to find the longest common prefix string amongst an array of strings.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n = strs.size();
        if(n == 1) return strs[0];
        
        string res = strs[0];
        
        for(int i=1; i<n; i++) {
            res = commonPrefix(res, strs[i]);
        }
        
        return res;
    }
    
    string commonPrefix(string str1, string str2) {
        if(str1.empty() || str2.empty()) return "";
        
        int n = min(str1.size(),str2.size());
        
        for(int i=0; i<n; i++) {
            if(str1[i] != str2[i]) {
                return str1.substr(0,i);
            }
        }
        
        return str1.substr(0,n);
    }
};
