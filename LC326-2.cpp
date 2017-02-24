// INT range: -2,147,483,648 to 2,147,483,647
// 1162261467 = 3^19
class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0) && (1162261467 % n == 0);
    }
};
