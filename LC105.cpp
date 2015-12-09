//Given preorder and inorder traversal of a tree, construct the binary tree.
//You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;
        if(preorder.size() != inorder.size()) return NULL;
        
        TreeNode* root = buildTree_sub(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        
        return root;
    }
    
    TreeNode* buildTree_sub(vector<int>& preorder, int pa, int pb, vector<int>& inorder, int ia, int ib) {
        if(preorder.empty()) return NULL;
        if((pa > pb) || (ia > ib)) return NULL;
        
        TreeNode* res = new TreeNode(preorder[pa]);
        if((pa == pb) && (ia == ib)) return res;
        
        int i = ia;
        for(i = ia; i <= ib; i++) {
            if(inorder[i] == res->val) break;
        }
        res->left = buildTree_sub(preorder, pa+1, pa-ia+i, inorder, ia, i-1);
        res->right = buildTree_sub(preorder, pb-ib+i+1, pb, inorder, i+1, ib);
        return res;
    }
    
};
