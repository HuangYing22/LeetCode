//O(n^2)
//vector只能装同一种元素，elements can also be vector
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i;
        int j;
        int temp;
        for(j=0; j<nums.size(); j++){
            for (i=0; i<nums.size()-1; i++) {
                    if ((nums[i] == 0) && (nums[i+1] !=0)) {
                        temp = nums[i];
                        nums[i] = nums[i+1];
                        nums[i+1] = temp;
                    }
            }
        }
    }
};
