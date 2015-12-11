//LC50
//Why runtime error? Recursive层数太多,占用内存太多 内存溢出 stack overflow
/*
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n > 0) return(x*myPow(x, n-1));
        return 1/myPow(x,0-n);
    }
};
*/

//Time Limit Exceeded
/*
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double res = x;
        if(n > 0) {
            for (int i=n; i>0; i--) {
                res *= x;
            }
            return res;
        } else {
            int p = 0-n;
            return 1/myPow(x,p);
        }
    }
};
*/

//AC
//Fast Power
class Solution {
public:
    double myPow(double x, int n) {
        //一般先讨论x是不是0和1
        if(x == 0.0) return 0.0; //0的几次乘方是undefined
        if(x == 1.0) return 1.0; //double的写法
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n > 0) {
            if (n%2 == 0)
                return myPow(x*x,n/2);
            return myPow(x*x,n/2)*x;
        } else {
            //Better写成:
	          int p = -(n+1);
            //int p = -1-n; //-21...48变成-n的时候不一定会怎么变
            //整数上下限不同,正数上限:21...47, 负数下限:-21...48
            //直接用p = 0-n会run time error
            return 1/(x*myPow(x,p));
        }
    }
};
