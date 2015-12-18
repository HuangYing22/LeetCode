//LC307
// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
// The update(i, val) function modifies nums by updating the element at index i to val.
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.

class NumArray {
public:
    NumArray(vector<int> &nums) {
        //sqrt_n = findSqrt(nums.size());
        sqrt_n = sqrt(nums.size());
        int sum = 0;
        int j = 1;
        for(int i=0; i<nums.size(); i++) {
            numArray.push_back(nums[i]);
            if(i == j * sqrt_n) {
                sum = nums[i];
                j++;
            } else {
                sum += nums[i];
            }
            sumArray.push_back(sum);
        }
    }

    void update(int i, int val) {
        int n = numArray.size();
        if(n <= i) return;
        
        int end = (i / sqrt_n + 1) * sqrt_n - 1;
        end = min(end, n-1);
        for(int j = i; j <= end ; j++) {
            sumArray[j] = sumArray[j] - numArray[i] + val;
        }
        
        numArray[i] = val;
        return;
    }

    int sumRange(int i, int j) {
        if((numArray.size() <= i) || (numArray.size() <= j)) return 0;
        if(i > j) return 0;
        if(i == j) return numArray[i];
        
        int start = (i / sqrt_n + 1) * sqrt_n; //i后面下一段开头的第一个元素
        int end = j / sqrt_n * sqrt_n; //j这一段开头的第一个元素
        
        int res = 0;

        if(start <= end) {
            if(start > i) { //算i这一段
                res += sumArray[start - 1] - sumArray[i] + numArray[i];
            }
            
            res += sumArray[j] - sumArray[end] + numArray[end]; //算j这一段
            
            //start == i的情况也在这里计算
            for(int k = start; k < end; k = k + sqrt_n) {
                res += sumArray[k + sqrt_n - 1] - sumArray[k] + numArray[k];
            }
            
        } else { //i,j in the same segment
            res = sumArray[j] - sumArray[i] + numArray[i]; 
        }
        
        return res;

    }
    
    /*
    int findSqrt(int n) {
        if(n == 0) return 0;
        if(n < 4) return 1;
        if(n < 9) return 2;
        if(n < 16) return 3;
        
        for(int i=4; i<n/4; i++) {
            if(i*i > n) return i;
        }
    }
    */
    
    vector<int> numArray;
    vector<int> sumArray;
    int sqrt_n;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
