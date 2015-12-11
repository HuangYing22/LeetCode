//LC98
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Given a binary tree, determine if it is a valid binary search tree (BST).
// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Time O(n)
// Space O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> val;
        
        while(!st.empty() || node != NULL) {
            if(node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                st.pop();
                val.push_back(node->val);
                node = node->right;
            }
        }
        
        for(int i=0; i<val.size()-1; i++) {
            if(val[i] >= val[i+1]) return false; //duplicate numbers also may exist
        }
        return true;
    }
};
