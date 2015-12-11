/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.
// You may only use constant extra space.
// The given tree could be any binary tree.

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()) {
            TreeLinkNode* node = q.front();
            q.pop();
            
            if(node == NULL) {
                if(q.empty()) break;
                q.push(NULL);
            } else {
                node->next = q.front();
                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
            }
        }
        return;
    }
};
        
