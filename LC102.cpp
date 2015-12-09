//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        
        queue<TreeNode*> qt;
        qt.push(root);
        qt.push(NULL);
        vector<int> resLevel;
        
        while(!qt.empty()) {
            TreeNode* curRoot = qt.front();
            qt.pop();
            if(curRoot == NULL) { //表示这一层已经结束,而且left right都已经进入了queue了
                res.push_back(resLevel);
                if(qt.empty()) break; //不判断此时queue是不是空的话,会再塞进一个NULL,就死循环了
                qt.push(NULL);
                resLevel.clear();
                continue;
            }
            resLevel.push_back(curRoot->val);
            if(curRoot->left != NULL) {
                qt.push(curRoot->left);
            }
            if(curRoot->right != NULL) {
                qt.push(curRoot->right);
            }
        }
        
        return res;
    }
};
