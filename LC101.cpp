//LC101
//正解
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if((root->left == NULL) && (root->right == NULL)) return true;
        if((root->left != NULL) && (root->right == NULL)) return false;
        if((root->left == NULL) && (root->right != NULL)) return false;
        return(isSymmetric(root->left, root->right));
    }
    
    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if((p == NULL) && (q == NULL)) return true;
        if((p == NULL) && (q != NULL)) return false;
        if((p != NULL) && (q == NULL)) return false;
        if(p->val != q->val) return false;
        return (isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left));
    }

};
