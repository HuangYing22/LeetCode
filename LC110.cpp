//LC110
//a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int diffLR = findDepth(root->left)-findDepth(root->right);
        return (isBalanced(root->left) && isBalanced(root->right) && (diffLR <= 1) && (diffLR >= -1));
    }
    
    int findDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1+max(findDepth(root->left),findDepth(root->right));
    }
};
