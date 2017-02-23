/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool hasPathSumRecur(TreeNode* root, int sum) {
        if(root == NULL) return (sum == 0);
        
        if(root->left == NULL) return hasPathSumRecur(root->right, sum - root->val);
        if(root->right == NULL) return hasPathSumRecur(root->left, sum - root->val);
        return (hasPathSumRecur(root->left, sum - root->val) || hasPathSumRecur(root->right, sum - root->val));
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        
        if(root->left == NULL) return hasPathSumRecur(root->right, sum - root->val);
        if(root->right == NULL) return hasPathSumRecur(root->left, sum - root->val);
        return (hasPathSumRecur(root->left, sum - root->val) || hasPathSumRecur(root->right, sum - root->val));
    }
};
