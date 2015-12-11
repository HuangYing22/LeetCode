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
// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        TreeLinkNode* pre = root;
        TreeLinkNode* head = root;
        
        while(pre->left != NULL) {
            pre->left->next = pre->right;
            TreeLinkNode* tail = pre->right;
            if(pre->next == NULL) {
                pre = head->left;
                head = pre;
            } else {
                pre = pre->next;
                tail->next = pre->left;
            }
        }
        return;
    }
};
