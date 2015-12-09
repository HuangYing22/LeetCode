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
        
        stack<TreeNode*> current;
        current.push(root);
        stack<TreeNode*> next;
        
        while(!current.empty()) {
            TreeNode* node = current.top();
            current.pop();
            next.push(node);
            
            if(node->left != NULL) {
                current.push(node->left);
            }
            
            if(node->right != NULL) {
                current.push(node->right);
            }
        }
        
        while(!next.empty()) {
            TreeNode* node = next.top();
            next.pop();
            res.push_back(node->val);
        }
        
        return res;
    }
};
