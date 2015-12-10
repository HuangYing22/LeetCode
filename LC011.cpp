//Two Pointer: while loop
//continue:这一轮什么也不做,直进下一轮
//break:直接出loop,不再循环

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty()) return 0;
        int minHeight;
        int curArea = 0;
        int resMaxArea = 0;

        int i = 0;
        int j = height.size() - 1;
        while(i < j) {
            if (height[i] < height[j]) {
                minHeight = height[i];
                curArea = minHeight* (j - i);
                if (curArea > resMaxArea) {
                    resMaxArea = curArea;
                }
                i ++;

                //break;
            } else {
                minHeight = height[j];
                curArea = minHeight* (j - i);
                if (curArea > resMaxArea) {
                    resMaxArea = curArea;
                }
                j --;

                //break;
            }
        }
        return resMaxArea;
    }
};
