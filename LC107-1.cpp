/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> resLevel;
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                res.push_back(resLevel);
                resLevel.clear();
                if(q.empty()) break;
                q.push(NULL);
            } else {
                resLevel.push_back(node->val);
                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
            }
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};
