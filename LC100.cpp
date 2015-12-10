/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Given two binary trees, write a function to check if they are equal or not.
// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == NULL) && (q == NULL)) return true;
        
        stack<TreeNode*> stP;
        stack<TreeNode*> stQ;
        stP.push(p);
        stQ.push(q);
        
        while(!stP.empty() && !stQ.empty()) {
            TreeNode* curP = stP.top();
            stP.pop();
            TreeNode* curQ = stQ.top();
            stQ.pop();
            
            if((curP == NULL) && (curQ == NULL)) continue;
            if((curP == NULL) && (curQ != NULL)) return false;
            if((curP != NULL) && (curQ == NULL)) return false;
            if(curP->val != curQ->val) return false;
            
            stP.push(curP->right);
            stP.push(curP->left);
            
            stQ.push(curQ->right);
            stQ.push(curQ->left);
        }
        
        return true;
        
    }
};
