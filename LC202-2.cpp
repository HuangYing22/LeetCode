class Solution {
private: 
    int trans(int n) {
        int res = 0;
        while (n != 0) {
            int tmp = n % 10;
            res += tmp * tmp;
            n /= 10;
        }
        return res;
    }
    
public:
    bool isHappy(int n) {
        unordered_set<int> used;
        
        if(n == 1) return true;
        used.insert(n);
        int tmp = trans(n);
        
        while(tmp != 1) {
            if(used.find(tmp) != used.end()) return false;
            used.insert(tmp);
            tmp = trans(tmp);
        }
        
        return true;
    }
};
