//正解 Binary Search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        return findMin(nums, 0, n-1, nums[0]);
    }
    int findMin(vector<int>& nums, int a, int b, int res) {
        if(a > b) return res;
        int mid = a + (b-a)/2;
        if(nums[mid] < nums[b]) { //右半边顺序是对的
            res = min(res, nums[mid]);
            return findMin(nums, 0, mid-1, res);
        } else { //左半边顺序是对的
            res = min(res, nums[a]);
            return findMin(nums, mid+1, b, res);
        }
    }
};
