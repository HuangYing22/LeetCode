/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
// The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if((p == NULL) || (q == NULL)) return root;
        
        if(p->val > q->val) swap(p,q);
        
        TreeNode* res = root; 
        while(res != NULL) {
            if(res->val > q->val) {
                res = res->left;
            }
            if(res->val < p->val) {
                res = res->right;
            } 
            if((res->val <= q->val) && (res->val >= p->val)) {
                return res;
            }
        }
        return res;
        
    }
};
