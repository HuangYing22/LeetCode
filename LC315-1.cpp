//LC315
// You are given an integer array nums and you have to return a new counts array.
// The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
// Given nums = [5, 2, 6, 1]
// Return the array [2, 1, 1, 0].

// Wrong Answer @input [0, 2, 1]
/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts = nums;
        if(nums.empty()) return counts;
        
        int n = nums.size();
        counts[n-1] = 0;
        if(n == 1) return counts;
        
        for(int i=n-2; i>=0; i--) {
            if(nums[i+1] >= nums[i]) {
                counts[i] = counts[i+1];
            } else {
                counts[i] = counts[i+1]+1;
            }
        }
        return counts;
    }
};
*/

// Time Limit Exceeded
// O(n^2)
/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty()) return {};
        
        int n = nums.size();
        vector<int> counts(n,0);
        //counts[n-1] = 0;
        if(n == 1) return counts;
        
        for(int i=n-2; i>=0; i--) {
            if(nums[i+1] == nums[i]) {
                counts[i] = counts[i+1];
            } else {
                for(int j=i+1; j<n; j++) {
                    if(nums[j] < nums[i]) {
                        counts[i]++;
                    }
                }
            }
        }
        return counts;
    }
};
*/
struct myTreeNode {
    int val;
    myTreeNode *left;
    myTreeNode *right;
    int count;
    int leftSize; //left subtree node counts
    myTreeNode(int x) : val(x), count(1), leftSize(0), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty()) return {};
        
        int n = nums.size();
        vector<int> counts(n,0);
        if(n == 1) return counts;
        
        myTreeNode* root = new myTreeNode(nums[n-1]);

        for(int i = n-2; i >= 0; i--) {
            int countSmaller = 0;
            addToTree(nums[i], root, countSmaller);
            counts[i] = countSmaller;
        }

        return counts;
    }
    
    void addToTree(int num, myTreeNode*& root, int& countSmaller) {
        myTreeNode* node = new myTreeNode(num);
        
        if(root == NULL) {
            root = node;
            return;
        }
        
        myTreeNode* cur = root;
        myTreeNode* pre = root;
        while(cur != NULL) {
            if(cur->val == num) {
                countSmaller += cur->leftSize;
                cur->count++;
                return;
            }

            if(cur->val > num) { //向左走
                cur->leftSize++;
                pre = cur;
                cur = cur->left;
            } else { //向右走
                countSmaller += cur->leftSize + cur->count;
                pre = cur;
                cur = cur->right;
            }
        }
        
        if(pre->val > num) {
            pre->left = node;
        } else {
            pre->right = node;
        }
        
        return;
    }
    
    /*
    void levelOrder(myTreeNode* root) {
        if(root == NULL) return;
        
        queue<myTreeNode*> qt;
        qt.push(root);
        qt.push(NULL);
        
        while(!qt.empty()) {
            myTreeNode* curRoot = qt.front();
            qt.pop();
            if(curRoot == NULL) { //表示这一层已经结束,而且left right都已经进入了queue了
                cout<<endl;
                if(qt.empty()) break; //不判断此时queue是不是空的话,会再塞进一个NULL,就死循环了
                qt.push(NULL);
                continue;
            }
            cout<<curRoot->val<<" ";
            if(curRoot->left != NULL) {
                qt.push(curRoot->left);
            }
            if(curRoot->right != NULL) {
                qt.push(curRoot->right);
            }
        }
        
        return;
    }
    */
};
