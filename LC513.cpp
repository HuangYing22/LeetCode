/* Given a binary tree, 
find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL. */

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q; // for level order traversal
        q.push(root);
        q.push(NULL);
        TreeNode* cur;
        int res = root->val;
        bool isNewRow = true;
        
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            if(cur == NULL) {
                if(!q.empty()) { // if this is not the last NULL
                    q.push(NULL); // use NULL to mark the end of current level
                    isNewRow = true;
                }
            } else {
                if(isNewRow) {
                    res = cur->val;
                    isNewRow = false;
                }
                if(cur->left != NULL) {
                    q.push(cur->left);
                }
                if(cur->right != NULL) {
                    q.push(cur->right);
                }
            }
        }
        
        return res;
    }
};
