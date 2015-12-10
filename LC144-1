/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Given a binary tree, return the preorder traversal of its nodes' values. 
// Recursive, not good solution
// O(nlogn) 一共logn层,每一层的每个元素都被push_back了一次
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        res.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        
        for(int i=0; i<left.size(); i++) {
            res.push_back(left[i]);
        }
        
        for(int i=0; i<right.size(); i++) {
            res.push_back(right[i]);
        }
        
        return res;
    }
};
