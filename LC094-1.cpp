//Given a binary tree, return the inorder traversal of its nodes' values.
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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        inorderTraversal_sub(root, res);
        return res;
    }
    
    void inorderTraversal_sub(TreeNode* root, vector<int>& res) {
        if(root == NULL) return;
        inorderTraversal_sub(root->left, res);
        res.push_back(root->val);
        inorderTraversal_sub(root->right, res);
        return;
    }
};
