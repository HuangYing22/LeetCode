//O(N^3)
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int resSum = nums[0];
        int curSum;
        int i,j,k;
        int size = nums.size();
        for (i=0;i<size-1;i++) {
            for (k=1; k<size-i;k++) {
                curSum = nums[i];
                for (j=i+1;j<=i+k;j++) {
                    if(curSum > resSum) {
                        resSum = curSum;
                    }
                    curSum += nums[j];
                }
            }
        }
        if (nums[size-1] > resSum) {
            resSum = nums[size-1];
        }
        return resSum;
    }
};
*/

//O(N^2)
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int resSum = nums[0];
        int curSum;
        int i,j;
        int size = nums.size();
        for (i=0;i<size;i++) {
            curSum = nums[i];
            for (j=i+1;j<size;j++) {
                if (curSum > resSum) {
                    resSum = curSum;
                }
                curSum += nums[j];
            }
        }
        return resSum;
    }
};
*/

//O(N)
//local: 以nums[i]为终点的subarr中, sum最大的那个sum
//global:从0,1,...,n-1,所有nums[i]
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global=nums[0];
        int local=nums[0];
        int n=nums.size();
        int i;
        if (nums.empty()) {
            return INT_MIN;
        }
        for (i=1;i<n;i++) {
            local = max(local+nums[i],nums[i]);
            global = max(local,global);
        }
        return global;
    }
};
