/* Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num 
calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).

Can you do it like a boss? 
Do it without using any builtin function like __builtin_popcount in c++ or in any other language. */

// Runtime Error, recursive in a stack, O(n2)
/* class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        if(num == 0) {
            res.push_back(0);
            return res;
        }
        
        if(num == 1) {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        
        res = countBits(num - 1);
        if(num % 2 == 0) {
            res.push_back(res[num / 2]);
        } else {
            res.push_back(res[num / 2] + 1);
        }
        
        return res;
    }
}; */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        
        for(int i = 1; i <= num; i ++) {
            if(i % 2 == 0) {
                res.push_back(res[i / 2]);
            } else {
                res.push_back(res[i / 2] + 1);
            }
        }
        
        return res;
    }
};
