class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numsRed = 0;
        int numsWhite = 0;
        int numsBlue = 0;
        int i;
        int size = nums.size();
        for (i=0;i<size;i++) {
            switch (nums[i]) {
                case 0:
                    numsRed ++;
                    break;
                case 1:
                    numsWhite ++;
                    break;
                case 2:
                    numsBlue ++;
                    break;
            }
        }
        for (i=0;i<numsRed;i++) {
            nums[i] = 0;
        }
        for (i=numsRed;i<numsRed+numsWhite;i++) {
            nums[i] = 1;
        }
        for (i=numsRed+numsWhite;i<size;i++) {
            nums[i] = 2;
        }
    }
};
