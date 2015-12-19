//LC307
// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
// The update(i, val) function modifies nums by updating the element at index i to val.
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.
// Segment Tree

// Definition for a segment tree node.
 struct SegTreeNode {
    int val;
    int low;
    int high;
    SegTreeNode *left;
    SegTreeNode *right;
    SegTreeNode(int x, int a, int b) : val(x), low(a), high(b), left(NULL), right(NULL) {}
 };
 
class NumArray {
    vector<int> numArray;
    SegTreeNode* root;

private:
    SegTreeNode* buildSegTree(vector<int> &nums, int a, int b) {
        if(nums.empty()) return NULL;
        if(a > b) return NULL;
        
        if(a == b) {
           SegTreeNode* node = new SegTreeNode(nums[a], a, a);
           return node; 
        }
        
        int mid = (a + b) / 2;
        SegTreeNode* node = new SegTreeNode(0, a, b);
        node->left = buildSegTree(nums, a, mid);
        node->right = buildSegTree(nums, mid+1, b);
        node->val = node->left->val + node->right->val;
        
        return node;
    }
    
    int sumRange(SegTreeNode* root, int i, int j) {
        if(root == NULL) return 0;
        
        SegTreeNode* cur = root;
        
        if((cur->low >= i) && (cur->high <= j)) return cur->val;
        if((cur->low > j) || (cur->high < i)) return 0;
        
        return sumRange(cur->left, i, j) + sumRange(cur->right, i, j);
    }
    
public:
    NumArray(vector<int> &nums) {
        if(!nums.empty()) {
            numArray = nums;
            root = buildSegTree(nums, 0, nums.size() - 1);
        }
    }

    void update(int i, int val) {
        if(numArray.size() <= i) return;

        SegTreeNode* cur = root;
        if((i < cur->low) || (i > cur->high)) return;
        
        while(1) {
            if((i == cur->low) && (i == cur->high)) {
                cur->val = val;
                break;
            }
            if((i >= cur->left->low) && (i <= cur->left->high)) {
                cur->val = cur->val - numArray[i] + val;
                cur = cur->left;
                continue;
            }
            if((i >= cur->right->low) && (i <= cur->right->high)) {
                cur->val = cur->val - numArray[i] + val;
                cur = cur->right;
                continue;
            }
        }
        
        numArray[i] = val;
        return;
    }

    int sumRange(int i, int j) {
        if(numArray.empty()) return 0;
        if((numArray.size() < i) || (numArray.size() < j)) return 0;
        if(i > j) return 0;
        if(i == j) return numArray[i];
        
        return sumRange(root, i, j);
    }
    

};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
