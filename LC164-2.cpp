1.求ceiling的算法
eg. LC164 maximum gap
a = kb;
a/b = k;
(a-1)/k = k-1;
(a-1)/k+1 = k;
int len = (maxVal - minVal - 1) / (n - 1) + 1; //求(max - min)/(n - 1)的ceiling

2. 桶的大小(桶里数的个数)最优的情况是 max-min均匀分布-1

3. int cnt = (maxVal - minVal) / len + 1;
在正好整除的情况下多一个桶, 但是其它情况下不 + 1就少了1个桶
