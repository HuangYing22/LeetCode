//LC108
//Binary Search Tree (Vale of all the nodes left-subtree must be less or equal to root;right-subtree must be greater)
//Recursive left and right subtree must also be BST

//BST(keep Balanced to make the cost O(logn))
//Balanced: left height and right height diff <= 1
//Search O(logn) Worst case unbalanced tree(lined list like structure): O(n)
//Insert O(logn)
//Remove O(logn)

//Insert and Remove may cause BST to be unbalanced!!
// Time Complexity O(n)
// T(n) = C + 2T(n/2) => T(n)正比于n
// Merge Sort: T(n) = n + 2T(n/2) => T(n)正比于nlogn

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* res = new TreeNode(0); //***动态声明
        if(nums.empty()) return NULL;
        res =  sortedArrayToBST(nums, 0, nums.size()-1);
        return res;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int a, int b) {
        TreeNode* res = new TreeNode(0);
        if(nums.empty()) return NULL;
        if(a > b) return NULL;
        
        if(a == b) {
            res->val = nums[a];
            return res;
        }
        
        int mid;
        if((b-a)%2 == 0) mid = a+(b-a)/2;
        else mid = a+(b-a)/2+1;
        
        res->val = nums[mid];
        res->left = sortedArrayToBST(nums, a, mid-1);
        res->right = sortedArrayToBST(nums, mid+1, b);
        
        return res;
    }
};

/*
Runtime error
...
TreeNode* res; //Wrong!!
...
if(a == b) {
res->val = nums[a];
            return res;
}
...
*/

//正解-不区分奇数偶数
    TreeNode* sortedArrayToBST(vector<int>& nums, int a, int b) {
        if(nums.empty()) return NULL;
        if(a > b) return NULL;
        int mid = a+(b-a+1)/2; //防止溢出
        TreeNode* res = new TreeNode(nums[mid]);
        res->left = sortedArrayToBST(nums, a, mid-1);
        res->right = sortedArrayToBST(nums, mid+1, b);
        
        return res;
    }
