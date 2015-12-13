//LC164
//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//Try to solve it in linear time/space.
//Return 0 if the array contains less than 2 elements.
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

//O(nlogn)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        
        int res = 0;
        mergeSort(nums);
        
        for(int i=0; i<n-1; i++) {
            if(nums[i+1]-nums[i] > res) {
                res = nums[i+1]-nums[i];
            }
        }
        
        return res;
        
    }
    
    void mergeSort(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        
        int mid = n/2;
        vector<int> a;
        vector<int> b;
        
        for(int k=0; k<mid; k++) {
            a.push_back(nums[k]);
        }
        
        for(int k=mid; k<n; k++) {
            b.push_back(nums[k]);
        }
        
        mergeSort(a);
        mergeSort(b);
        
        int na = a.size();
        int nb = b.size();
        int i = 0;
        int j = 0;
        
        while((i < na) && (j < nb)) {
            if(a[i] < b[j]) {
                nums[i+j] = a[i];
                i++;
            } else {
                nums[i+j] = b[j];
                j++;
            }
        }
        
        while(i<na) {
            nums[i+j] = a[i];
            i++;
        }
        
        while(j<nb) {
            nums[i+j] = b[j];
            j++;
        }
        
        return;
    }
};
