/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Given a binary tree, return the preorder traversal of its nodes' values.
//Recuisive: Better way than 144-1
//Time O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        preorderTraversal_sub(root, res);
        return res;
    }
    
    void preorderTraversal_sub(TreeNode* root, vector<int>& res) {
        if(root == NULL) return;
        res.push_back(root->val);
        preorderTraversal_sub(root->left, res);
        preorderTraversal_sub(root->right, res);
        return;
    }
};
