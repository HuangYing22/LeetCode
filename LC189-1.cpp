//LC189
// Rotate an array of n elements to the right by k steps.
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
// do it in-place with O(1) extra space

class Solution {
public:
/*
//AC
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        for(int i=0; i<(n-k); i++) {
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.begin()+n-k);
        return;
    }
*/

/*
//AC
     void rotate(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        k %= n;
        if(k == 0) return;
        
        for(int i=n-k; i<n; i++) res.push_back(nums[i]);
        for(int i=0; i<n-k; i++) res.push_back(nums[i]);
        
        nums = res;
        return;
    }
*/

/*
//Time limit exceeded
     void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k == 0) return;
        
        for(int i=1; i<=k; i++) {
            int tmp = nums[n-1];
            for(int j=n-1; j>0; j--) {
                nums[j] = nums[j-1];
            }
            nums[0] = tmp;

        }
        return;
    }

};
*/

// 正解
// Rotate an array of n elements to the right by k steps.
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
// do it in-place with O(1) extra space

class Solution {
public:
    int gcd(int a,int b) {
        if(b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0) {
            return;
        }

        for(int i = 0; i < gcd(n, k); i++) {
            cout<<"i = "<<i<<endl;
            printVector(nums);
            int prev = i;
            int cur = i;
            int tmp = nums[i];
            while(1) {
                cur -= k;
                if(cur < 0) {
                    cur += n;
                }
                cout<<"prev = "<<prev<<endl;
                cout<<"cur = "<<cur<<endl;
                if(cur == i) {
                    nums[prev] = tmp;
                    break;
                }
                nums[prev] = nums[cur];
                prev = cur;
                printVector(nums);
            }
        }
    }

    void printVector(vector<int>& nums) {
        if(nums.empty()) return;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
};
