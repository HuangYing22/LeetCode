//LC303
// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
// You may assume that the array does not change.
// There are many calls to sumRange function.

class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            numArray.push_back(nums[i]);
            sum += nums[i];
            sumArray.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if((numArray.size() <= i) || (numArray.size() <= j)) return 0;
        return sumArray[j] - sumArray[i] + numArray[i];
        
    }
    
    vector<int> numArray;
    vector<int> sumArray;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
