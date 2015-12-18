//LC16
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
// Return the sum of the three integers. 
// You may assume that each input would have exactly one solution.
// For example, given array S = {-1 2 1 -4}, and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int res;
        int curSum;
        int diff;
        int minDiff = INT_MAX;
        int a = 0;
        sort(nums.begin(), nums.end());
        
        while(a < n) {
            int b = a+1;
            int c = n-1;
            while(b < c) {
                curSum = nums[a] + nums[b] + nums[c];
                if(curSum == target) return target;
                diff = curSum - target;
                if(abs(diff) < abs(minDiff)) {
                    minDiff = diff;
                    res = curSum;
                }
                if(diff > 0) {
                    while(nums[c] == nums[c-1]) {
                        c--;
                    }
                    c--;
                } else {
                    while(nums[b] == nums[b+1]) {
                        b++;
                    }
                    b++;
                }
                
            }
            
            while(nums[a] == nums[a+1]) {
                a++;
            }
            a++;
        }
        
        return res;
    }
};
