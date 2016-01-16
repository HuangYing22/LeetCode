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
        
        //尽量不要用unordered_multimap
        unordered_map<int, int> mapA;
        int n = numsA.size();
        for(int i = 0; i < n; i ++) {
            unordered_map<int, int>::iterator it = mapA.find(target - numsA[i]);
            if(it != mapA.end()) {
                res.push_back(it->second);
                res.push_back(i + 1);
                break;
            }
            mapA[numsA[i]] = i + 1;
        }
        
        return res;
    }

};


