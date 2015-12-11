//LC111
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if((root->left == NULL) && (root->right == NULL)) return 1;
        if(root->left == NULL) return 1 + minDepth(root->right); //不单独列出这种情况的话会给出1;因为左边是0
        if(root->right == NULL) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
};
