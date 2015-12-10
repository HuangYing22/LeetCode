/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// Follow up for problem "Populating Next Right Pointers in Each Node".
// What if the given tree could be any binary tree? Would your previous solution still work?
// You may only use constant extra space.
// Time O(n)
// Space O(b) breadth of the tree
// Extra space O(b)
// Same solution as LC116

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        queue<TreeLinkNode*> cur;
        queue<TreeLinkNode*> next;
        cur.push(root);
        
        while(!cur.empty()) {
            while(!cur.empty()) {
                TreeLinkNode* node = cur.front();
                cur.pop();
                if(node->left != NULL) next.push(node->left);
                if(node->right != NULL) next.push(node->right);
            
                if(cur.empty()) break;
                node->next = cur.front();
            }
            if(!next.empty()) swap(cur,next);
        }
        
        return;
    }
};
