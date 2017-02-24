／＊ Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty 
and the majority element always exist in the array. ＊／

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        if(n == 1) return nums[0];
        
        for(int i = 0; i < n; i ++) {
            unordered_map<int, int>::iterator it = map.find(nums[i]);
            if(it != map.end()) {
                it->second ++;
                if(it->second > (n / 2)) return it -> first;
            } else {
                map[nums[i]] = 1;
            }
        }
        
        return nums[0];
        
    }
};
