//Time O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n<3) return res;
        
        sortVector(nums);
        
        for(int a=0; a<n; a++) {
            //每次a移到新的一项之后,如果大于0,后面所有的一定都大于0,不用再看了,直接return现有的res
            //没有的话会time exceeded,虽然是n^2复杂度,但是n的数目很大,还是会影响速度
            if(nums[a] > 0) return res; 
            
            int c = n-1;
            int b = a+1;
            
            //每一次a+1或者b+1或者c-1时候都要查重
            while(b < c) {
                int sum = nums[a]+nums[b]+nums[c];
                if(sum < 0) {
                    while(nums[b] == nums[b+1]) {
                        b++;
                    }
                    b++;
                }
                if(sum > 0) {
                    while(nums[c] == nums[c-1]) {
                        c--;
                    }
                    c--;
                }
                if(sum == 0) {
                    vector<int> cur;
                    cur.push_back(nums[a]);
                    cur.push_back(nums[b]);
                    cur.push_back(nums[c]);
                    res.push_back(cur);
                    while(nums[b] == nums[b+1]) {
                        b++;
                    }
                    b++;
                }
                
            }
            while(nums[a] == nums[a+1]) {
                a++;
            }
        }
        return res;
    }
    
    void sortVector(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        
        if (n <= 1) return;
        
        vector<int> a,b;
        for(int l = 0; l < n/2; l++) {
            a.push_back(nums[l]);
        }
        for(int l = n/2; l < n; l++) {
            b.push_back(nums[l]);
        }

        sortVector(a);
        sortVector(b);
        
        int na = a.size();
        int nb = b.size();
        int i = 0;
        int j = 0;
        while((i < na) && (j < nb)){
            if(a[i] < b[j]) {
                nums[i+j] = a[i];
                i++;
            } else {
                nums[i+j] = b[j];
                j++;
            }
        }
        if(j < nb) {       
            for(int k=j; k<nb; k++) {
                nums[i+k] = b[k];
            }
        }
        if(i < na) {
            for(int k=i; k<na; k++) {
                nums[j+k] = a[k];
            }
        }
        return;
    }

};
