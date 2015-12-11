//LC226
/*
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        if((root->left == NULL) && (root->right == NULL)) return root;
       
        invertTree(root->right);
        invertTree(root->left);
        
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        return root;
    }
};
*/

//Better正解
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        if((root->left == NULL) && (root->right == NULL)) return root;
       
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        root->left = invertTree(rightNode);
        root->right = invertTree(leftNode);
        
        return root;
    }
};
