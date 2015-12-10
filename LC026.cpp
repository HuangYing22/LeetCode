class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sizeOld = nums.size();
        int i;
        for (i=0; i<sizeOld-1; i++) {
            if (nums[i] < nums[i+1]) {
                nums.push_back(nums[i]);
            }
        }
        if (sizeOld > 0) {
            nums.push_back(nums[sizeOld-1]);
        }
        int sizeNew = nums.size();
        int res = sizeNew - sizeOld;
        for (i=0;i<res;i++) {
            nums[i] = nums[sizeOld + i];
        }
        return res;
    }
};
