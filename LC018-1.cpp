// LC18
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
// For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
// A solution set is:
//    (-1,  0, 0, 1)
//    (-2, -1, 1, 2)
//    (-2,  0, 0, 2)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4) return res;
     
        sort(nums.begin(), nums.end());
        for(int d = 0; d < n; d ++) {
            //Cannot return here since numbers could be negative
            //eg [1,-2,-5,-4,-3,3,3,5] target -11
            //if(nums[d] > target) return res;
            for(int a = d + 1; a < n; a ++) {
                int b = a + 1;
                int c = n - 1;
                while(b < c) {
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if(sum > target) {
                        while(nums[c] == nums[c - 1]) {
                            c --;
                        }
                        c --;
                    } else if(sum < target) {
                        while(nums[b] == nums[b + 1]) {
                            b ++;
                        }
                        b ++;
                    } else {
                        vector<int> r;
                        r.push_back(nums[d]);
                        r.push_back(nums[a]);
                        r.push_back(nums[b]);
                        r.push_back(nums[c]);
                        res.push_back(r);
                        
                        while(nums[b] == nums[b + 1]) {
                            b ++;
                        }
                        b ++;
                    }
                }
                while(nums[a] == nums[a + 1]) {
                    a ++;
                }
            }
            while(nums[d] == nums[d + 1]) {
                d ++;
            }
        }
        return res;
        
    }
};
