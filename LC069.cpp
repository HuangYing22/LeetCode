/* Implement int sqrt(int x).
Compute and return the square root of x.
*/

// Time Limit Exceeded
/*
class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return 0;
        if(x <= 1) return x;
        
        int res;
        for(res = 2; res * res <= x; res ++) {
            if(res * res == x) return res;
        }
        
        return res - 1;
    }
};
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        
        // mid * mid might be larger than int_max, since end = 50000 is used
        long long val = x;
        long long begin = 1;
        long long end = 50000; //sqrt(int_max) = 46340
        long long mid;
        
        /*
        while(begin < end) is wrong
        consider (begin,end,val) = (1,2,4)
        mid = 1, mid * mid < val, (mid + 1) * (mid + 1) == val
        begin = mid + 1 = 2
        while loop stops at (begin,end,mid) = (2,2,1)
        */
        
        while(begin <= end) {
            mid = begin + (end - begin)/2;
            if(mid * mid == val) return (int)mid;
            if(mid * mid > val) {
                end = mid - 1;
            } else {
                if((mid + 1) * (mid + 1) > val) return (int)mid;
                begin = mid + 1;
            }
        }
        return (int)mid;
    }
};

/* Alternatively
while(begin < end) {
... ...
}
return (int) begin;
*/
