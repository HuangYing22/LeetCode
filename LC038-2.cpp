class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) return "";
        if(n == 1) return "1";
        string res = "1";
        
        for(int i = 1; i < n; i ++) {
            res = iter(res);
        }
        
        return res;
    }
    
    string iter(string s) {
        int n = s.length();
        if(n == 0) return "";
        
        string res;
        char c = s[0];
        int count = 1;
        
        for(int i = 1; i < n; i ++) {
            if(s[i] == c) {
                count ++;
            } else {
                res += to_string(count);
                res.push_back(c);
                c = s[i];
                count = 1;
            }
        }
        
        res += to_string(count);
        res.push_back(c);
        return res;
    }
};
