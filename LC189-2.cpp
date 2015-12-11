//正解2
//k = 3
//1 2 3 4 5 6 7
//7 6 5 4 3 2 1
//(5 6 7) (1 2 3 4)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1) return;
        k %= n;
        if(k == 0) return;
        reverseArray(nums, 0, n - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
        return;
    }
    /*
    void reverseArray(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty() || (n == 1)) return;
        for(int i=0; i<n/2; i++) {
            int tmp = nums[i];
            nums[i] = nums[n-1-i];
            nums[n-1-i] = tmp;
        }
        return;
    }
    */
    void reverseArray(vector<int>& nums, int start, int end) {
        if(nums.empty()) return;
        if(start == end) return;
        
        for(int i=0; i<(end-start + 1)/2; i++) {
            /*
            int tmp = nums[start + i];
            nums[start + i] = nums[end - i];
            nums[end - i] = tmp;
            */
            swap(nums[start + i],nums[end - i]); //对于两个同样type的东西都可以
        }
        return;
    }
};
