//LC278
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(!isBadVersion(n)) return 0;
        return fBV(1,n);
    }
    
    int fBV(int a, int b) {
        if(a == b) {
            if(isBadVersion(a)) return a;
            return a+1;
        }
        if(b-a == 1) {
            if(isBadVersion(a)) return a;
            return b;
        }
        //m是a,b的中点,但是a+b可能会超出INT_MAX
        //int m = (a+b)/2;
        int m = a+(b-a)/2;
        if(isBadVersion(m)) return fBV(1,m-1);
        return fBV(m+1,b);
    }
};
