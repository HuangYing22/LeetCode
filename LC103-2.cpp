/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
            resLevel = zigzag(cur, next, true);
            res.push_back(resLevel);
            resLevel.clear();
            resLevel = zigzag(next, cur, false);
            if(resLevel.empty()) break;
            res.push_back(resLevel);
            resLevel.clear();
        }
        return res;
    }
    
    vector<int> zigzag(stack<TreeNode*>& st1, stack<TreeNode*>& st2, bool dir) {
        vector<int> res;
        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            res.push_back(node->val);
            if(dir) {
                if(node->left != NULL) st2.push(node->left);
                if(node->right != NULL) st2.push(node->right);
            } else {
                if(node->right != NULL) st2.push(node->right);
                if(node->left != NULL) st2.push(node->left);
            }
        }
        return res;
    }
};
