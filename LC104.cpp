//LC104
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
/*
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if((root->left == NULL) && (root->right == NULL)) return 1;
        if(root->left == NULL) return 1+maxDepth(root->right);
        if(root->right == NULL) return 1+maxDepth(root->left);
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
*/

//Better正解
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
