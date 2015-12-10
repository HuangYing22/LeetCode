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
//Iteratively
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            res.push_back(cur->val);
            if(cur->right != NULL) {
                st.push(cur->right);
            }
            if(cur->left != NULL) {
                st.push(cur->left);
            }
        }
        
        return res;
    }
};
