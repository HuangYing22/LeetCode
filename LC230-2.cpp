//LC230
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
// Without a vector, use less space
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        
        int count = 0;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        
        while(!st.empty() || (cur != NULL)) {
            if(cur != NULL) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                count++;
                if(count == k) return cur->val;
                cur = cur->right;
            }
        }
    }
};
