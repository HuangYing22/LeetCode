//LC88
//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
//The number of elements initialized in nums1 and nums2 are m and n respectively.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        if(m == 0) {
            nums1 = nums2;
            return;
        }
        
        int i = 0;
        int j = 0;
        int size = m;
        
        while((i < size) && (j < n)) {
            if(nums1[i] < nums2[j]) {
                i++;
            } else {
                for(int k=size; k>i; k--) {
                    nums1[k] = nums1[k-1];
                }
                nums1[i] = nums2[j];
                j++;
                size++;
            }
        }
        
        while(j < n) {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
        
        return;
    }
};
