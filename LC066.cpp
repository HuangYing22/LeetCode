// LC66
// Given a non-negative number represented as an array of digits, plus one to the number.
// The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res = digits;
        if(digits.empty()) return res;
        
        int n = digits.size();
        int c = 1;
        for(int i = n - 1; i >= 0; i --) {
            res[i] ++;
            c = res[i] / 10;
            res[i] %= 10;
            
            if (c == 0) return res;
        }
        
        res.insert(res.begin(), 1);
        return res;
    }
};
