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
        
        queue<TreeNode*> cur;
        queue<TreeNode*> next;
        cur.push(root);
        vector<int> resLevel;
        
        while(!cur.empty()) {
            while(!cur.empty()) {
                TreeNode* node = cur.front();
                cur.pop();
                resLevel.push_back(node->val);
                if(node->left != NULL) {
                    next.push(node->left);
                }
                if(node->right != NULL) {
                    next.push(node->right);
                }
            }
            res.push_back(resLevel);
            resLevel.clear();
            if(next.empty()) break;
            swap(cur,next);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};
