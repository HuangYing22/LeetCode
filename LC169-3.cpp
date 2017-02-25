class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int vote = 1;
        int cur = nums[0];
        for(int i = 0; i < n; i ++) {
            if(nums[i] == cur) vote ++;
            else vote --;
            if(vote == 0) {
                vote = 1;
                cur = nums[i];
            }
        }
        
        return cur;
    }
};
