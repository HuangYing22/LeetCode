/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Invert a binary tree.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;

        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if(cur->left != NULL) st.push(cur->left);
            if(cur->right != NULL) st.push(cur->right);
            swap(cur->left,cur->right);
        }
        return root;
    }
};
