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
        
        while(j < n) {
            if(i == m+j) {
                nums1.insert(nums1.begin()+m+j, nums2[j]);
                j++;
                continue;
                //必须要有continue,否则i越过m+j之后还会继续比较nums1[i]和nums2[j],i++ 造成run time error
            }
            if(nums1[i] < nums2[j]) {
                i++;
            } else {
                nums1.insert(nums1.begin()+i, nums2[j]);
                j++;
            }
        }
        
        //用nums1.insert()的同时必须要删掉多余的0
        nums1.erase(nums1.begin()+m+n, nums1.end());
        return;
    }
};
