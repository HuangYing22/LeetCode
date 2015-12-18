
/*1.求ceiling的算法
eg. LC164 maximum gap
a = kb;
a/b = k;
(a-1)/k = k-1;
(a-1)/k+1 = k;
int len = (maxVal - minVal - 1) / (n - 1) + 1; //求(max - min)/(n - 1)的ceiling

2. 桶的大小(桶里数的个数)最优的情况是 max-min均匀分布-1

3. int cnt = (maxVal - minVal) / len + 1;
不 + 1就少了1个桶

4. Another way to calc res gap
...
        int prev = 0;
        
        for(int i=0; i<cnt; i++) {
            if(buckets[i].empty()) {
                continue;
            }
            res = max(res, buckets[i][0] - buckets[prev][1]);
            prev = i;
        }
...
*/

//LC164
//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//Try to solve it in linear time/space.
//Return 0 if the array contains less than 2 elements.
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        
        int maxVal = nums[0];
        int minVal = nums[0];
        
        for(int i=0; i<n; i++) {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }
        
        int length = (maxVal - minVal -1) / (n - 1) + 1; //(max - min)/(n - 1)的ceiling
        int cnt = (maxVal - minVal) / length + 1; //不 + 1就少了1个桶
        
        vector<vector<int>> buckets(cnt, vector<int>());
        
        for(int i=0; i<n; i++) {
            int index = (nums[i] - minVal) / length;
            
            if(buckets[index].empty()) {
                buckets[index].push_back(nums[i]);
                buckets[index].push_back(nums[i]);
            } else {
                buckets[index][0] = min(buckets[index][0], nums[i]); //min val in bucket
                buckets[index][1] = max(buckets[index][1], nums[i]); //max val in bucket
            }
        }
        
        int res = 0;
        
        for(int i=0; i<cnt-1; i++) {
            if(buckets[i].empty()) {
                continue;
            }
            int j = i + 1;
            while(buckets[j].empty()) {
                j++;
            }
            res = max(res, buckets[j][0] - buckets[i][1]);
        }
        
        return res;
    }
};
