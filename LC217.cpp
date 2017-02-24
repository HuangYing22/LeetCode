/* Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct. */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return false;
        
        unordered_set<int> set;
        for(int i = 0; i < n; i ++) {
            if(set.find(nums[i]) != set.end()) return true;
            set.insert(nums[i]);
        }
        return false;
    }
};
