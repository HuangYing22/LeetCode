/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Iteratively
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* pre = NULL;
        
        while(!st.empty()) {
            TreeNode* cur = st.top();
            //pre != NULL保证第一次看到某个TreeNode左边或右边为空时,不会误以为到头了而开始回溯
            if(((cur->left == NULL) && (cur->right == NULL)) || ((pre != NULL) && ((cur->left == pre) || (cur->right == pre)))) {
                st.pop();
                res.push_back(cur->val);
                pre = cur;
            } else {
                if(cur->right != NULL) {
                    st.push(cur->right);
                }
                if(cur->left != NULL) {
                    st.push(cur->left);
                }
            }
        }
        
        return res;
    }
};
