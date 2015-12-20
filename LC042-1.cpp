//LC42
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        
        int left = 0;
        int right = height.size() - 1;
        int start;
        int cur;
        int res = 0;
        bool isLeft = true;
        
        while(height[left] < height[left + 1]) { //find the highest from the left
            left ++;
        }
        
        while(height[right] < height[right - 1]) { //find the highest from the right
            right --;
        }
        
        while(left < right) {
            if(height[left] < height[right]) {
                start = left;
                cur = start + 1;
                isLeft = true;
            } else {
                start = right;
                cur = start - 1;
                isLeft = false;
            }
            
            while(height[cur] < height[start]) {
                res += height[start] - height[cur];
                if(isLeft) {
                    cur ++; //left
                } else {
                    cur --; //right
                }
            }
            
            if(isLeft) {
                left = cur; //left;
            } else {
                right = cur; //right;
            }
        }
        
        return res;
    }
};
