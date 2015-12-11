//LC114
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        if((root->left == NULL) && (root->right == NULL)) return;
        
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        flatten(leftNode);
        flatten(rightNode);

        root->right = leftNode;
        root->left = NULL; //不加这一句会[1,2] runtime error why?? 为什么不是wrong answer?
        
        TreeNode* ptr = root;
        while(ptr->right != NULL) {
            ptr = ptr->right;
        }
        ptr->right = rightNode;

        return;
    }
};
