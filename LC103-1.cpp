/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Given a binary tree, return the zigzag level order traversal of its nodes' values. 
 // (ie, from left to right, then right to left for the next level and alternate between).
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        vector<int> resLevel;
        stack<TreeNode*> cur;
        stack<TreeNode*> next;
        cur.push(root);
        
        while(!cur.empty() || !next.empty()) {
            while(!cur.empty()) {
                TreeNode* node = cur.top();
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

            while(!next.empty()) {
                TreeNode* node = next.top();
                next.pop();
                resLevel.push_back(node->val);
                if(node->right != NULL) {
                    cur.push(node->right);
                }
                if(node->left != NULL) {
                    cur.push(node->left);
                }
            }
            if(resLevel.empty()) break;
            res.push_back(resLevel);
            resLevel.clear();
        }
        
        return res;
    }
};
