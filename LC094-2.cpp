/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //Non-recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(!st.empty() || cur != NULL) {
           if(cur != NULL) {
               st.push(cur);
               cur = cur->left; //一直找到最左边为止
           } else {
               cur = st.top();
               st.pop();
               res.push_back(cur->val);
               cur = cur->right;
           }
        }
        
        return res;
    }
};
