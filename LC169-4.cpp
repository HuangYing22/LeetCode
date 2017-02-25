class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int count;
        
        for(int i = 0; i < 32; i ++) {
            count = 0;
            for(int j = 0; j < n; j ++) {
                if(((nums[j] >> i) & 1) == 1) count ++;
            }
            
            if(count > n / 2) res |= 1 << i;
        }
        
        return res;
    }
};
