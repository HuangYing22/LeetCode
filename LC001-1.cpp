//At the end of “class” there must be a “;”
//res.push_back(); 从后面加
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int i, j;
        for (i=0; i<nums.size()-1; i++){
            for (j=i+1; j<nums.size(); j++) {
                if (nums[j] == (target - nums[i])) {
                    res.push_back(i+1);
                    res.push_back(j+1);
                }
            }
        }
        
        return res;
    }
};
