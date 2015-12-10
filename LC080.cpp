class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sizeOld = nums.size();
        int i;
        int counter = 0;
        if (sizeOld > 0) {
            nums.push_back(nums[0]);
            counter = 1;
        }
        for (i=1;i<sizeOld;i++) {
            if (nums[i] > nums[i-1]) {
                nums.push_back(nums[i]);
                counter = 1;
            } else {
                if (counter <2) {
                    nums.push_back(nums[i]);
                    counter ++;
                }
            }
        }
        int sizeNew = nums.size();
        int res = sizeNew - sizeOld;
        for (i=0;i<res;i++) {
            nums[i] = nums[sizeOld + i];
        }
        return res;
    }

};
