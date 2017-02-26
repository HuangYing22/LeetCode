/* Given a non-empty array of integers, 
return the third maximum number in this array. 
If it does not exist, return the maximum number. 

The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.

Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum. */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int first = nums[0];
        int second = nums[0];
        int third = nums[0];
        
        for(int i = 1; i < n; i ++) {
            if((nums[i] == first) || (nums[i] == second) || (nums[i] == third)) continue;
            
            if((first == second) && (second == third)) {
                if(nums[i] < third) {
                    third = nums[i];
                } else {
                    first = nums[i];
                }
                continue;
            }
            if(first == second) {
                if(nums[i] < third) {
                    second = third;
                    third = nums[i];
                } else if(nums[i] > first) {
                    first = nums[i];
                } else {
                    second = nums[i];
                }
                continue;
            }
            if(second == third) {
                if(nums[i] < third) {
                    third = nums[i];
                } else if(nums[i] > first) {
                    second = first;
                    first = nums[i];
                } else {
                    second = nums[i];
                }
                continue;
            }
            if(nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            } else if(nums[i] > second) {
                third = second;
                second = nums[i];
            } else if(nums[i] > third) {
                third = nums[i];
            }
            
        }
        
        if((first == second) || (third == second)) return first;
        return third;
    }
};
