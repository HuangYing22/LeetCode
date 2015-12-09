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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        postorderTraversal_sub(root, res);
        return res;
    }
    
    void postorderTraversal_sub(TreeNode* root, vector<int>& res) {
        if(root == NULL) return;
        postorderTraversal_sub(root->left, res);
        postorderTraversal_sub(root->right, res);
        res.push_back(root->val);
        return;
    }
};
