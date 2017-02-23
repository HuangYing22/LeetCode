//Declare vector<int> numsRemovedVal的时候，是空的vector, size是0
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res;
        int numValue = 0;
        int i;
        vector<int> numsRemovedVal;
        for (i=0; i<nums.size(); i++) {
            if (nums[i] == val) {
                numValue ++;
            } else {
                numsRemovedVal.push_back(nums[i]);
            }
        }
        res = nums.size()-numValue;
        for (i=0; i<res; i++) {
            nums[i] = numsRemovedVal[i];
        }
        return res;
    }
};
