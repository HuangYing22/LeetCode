/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        res.push_back(root->val);
        while(!q1.empty()) {
            while(!q1.empty()) {
                TreeNode* node = q1.front();
                q1.pop();
            
                if(node->left != NULL) {
                    q2.push(node->left);
                }
                if(node->right != NULL) {
                    q2.push(node->right);
                }
            }
            if(!q2.empty()) {
                res.push_back(q2.back()->val); //vector/queue都可以用back看最后一个元素,只不过queue不能pop出来
                swap(q1,q2);
            }
        }
        
        return res;
    }
};
