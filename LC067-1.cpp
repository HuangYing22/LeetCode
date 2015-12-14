//LC67
//Given two binary strings, return their sum (also a binary string).
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()) return b;
        if(b.empty()) return a;
        
        int na = a.size();
        int nb = b.size();
        if(na > nb) {
            swap(a,b);
        }
        string res = b;
        
        int i = min(na,nb)-1;
        int j = max(na,nb)-1;
        char c = '0';
        
        while(i >= 0) {
            if(((a[i] == '1') && (c == '0')) || ((a[i] == '0') && (c == '1'))) {
                if(res[j] == '0') {
                    res[j] = '1';
                    c = '0';
                } else {
                    res[j] = '0';
                    c = '1';
                }
            }
            i--;
            j--;
        }
        
        while((j >= 0) && (c == '1')) {
            if(res[j] == '0') {
                res[j] = '1';
                c = '0';
                break;
            }
            res[j] = '0';
            j--;
        }
        
        if(c == '1') {
            res.insert(res.begin(),'1');
        }
        return res;
    }
};
