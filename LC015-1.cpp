//LC15 3Sum
//Time O(n^3)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
                int n = nums.size();
        if(n<3) return res;
        
        sortVector(nums);
        if(nums[0] > 0) return res;

        vector<int> first;
        
        for(int i=0; i<n; i++) {
            for(int l=0; l<first.size(); l++) {
                if(first[l] == nums[i]) i++;
            }
            first.push_back(nums[i]);
            
            vector<int> second; //建在这一层
            for(int j=i+1; j<n; j++) {
                for(int l =0; l<second.size(); l++) {
                    if(second[l] == nums[j]) j++;
                }
                
                vector<int> third; //建在这一层
                 for(int k=j+1; k<n; k++) {
                    for(int l=0; l<third.size(); l++) {
                        if(third[l] == nums[k]) k++;
                    }
                    if(nums[i]+nums[j]+nums[k] == 0) {
                       vector<int> cur;
                       cur.push_back(nums[i]);
                       cur.push_back(nums[j]);
                       cur.push_back(nums[k]);
                       res.push_back(cur);
                   }
               }
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
