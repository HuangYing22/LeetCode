//** LC136
//Require O(n) time
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0; i<n; i++) {
            //cout<<"Bef ^:"<<res<<endl;
            res ^= nums[i];
	          //^Binary 0^0 = 0, 1^0 = 1, 0^1 = 0, 1^1 = 0
	          //任何数和0^都是它本身
            //cout<<"Aft ^:"<<res<<endl;
        }
        return res;
    }

};
