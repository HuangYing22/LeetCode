//LC42
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

//**正解2
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3) return 0;
        
        int res = 0;
        int maxVal = height[0];
        int maxInd = 0;
        
        for(int i=0; i<n; i++) {
            if(height[i] > maxVal) {
                maxVal = height[i];
                maxInd = i;
            }
        }
        
        int tmp = height[0];
        
        for(int i=1; i<maxInd; i++) {
            tmp = max(tmp, height[i]); //if height[i] > tmp, then tmp = height[i]; res += 0, res keeps unchanged
            res += tmp - height[i];
        }
        
        tmp = height[n-1];
        
        for(int i=n-2; i>maxInd; i--) {
            tmp = max(tmp, height[i]);
            res += tmp - height[i];
        }
        
        return res;
    }
};
