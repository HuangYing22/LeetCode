// LC 1
// Given an array of integers, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution.
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2
class Solution {
public:
    vector<int> twoSum(vector<int>& numsA, int target) {
        vector<int> res;
        if(numsA.empty()) return res;
        
        vector<int> copyA = numsA;
        sort(numsA.begin(), numsA.end());
        //if(numsA[0] > target) return res; //wrong: numbers could be negative
        
        int n = numsA.size();
        int i = 0;
        int j = n - 1;
        while(i < j) {
            if(numsA[i] + numsA[j] == target) {
                res.push_back(numsA[i]);
                res.push_back(numsA[j]);
                break;
            }
            if(numsA[i] + numsA[j] < target) {
                i ++;
                continue;
            }
            if(numsA[i] + numsA[j] > target) {
                j --;
                continue;
            }
        }
        
        if(res.empty()) return res;
        
        for(i = 0; i < n; i++) {
            if((copyA[i] == res[0]) || (copyA[i] == res[1])) {
                res.push_back(i + 1);
                continue;
            }
        }
        
        res.erase(res.begin(), res.begin() + 2);
        return res;
    }

};


