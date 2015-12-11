//LC95
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
class Solution {
private:
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(NULL);
            return res;
        }
        if(start == end) {
            TreeNode* node = new TreeNode(start);
            res.push_back(node);
            return res;
        }
        
        for(int i=start; i<=end; i++) {
            vector<TreeNode*> leftTrees = generateTrees(start, i-1);
            vector<TreeNode*> rightTrees = generateTrees(i+1, end);
            
            for(int j=0; j<leftTrees.size(); j++) {
                for(int k=0; k<rightTrees.size(); k++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = leftTrees[j];
                    node->right = rightTrees[k];
                    res.push_back(node);
                }
            }
        }
        
        return res;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0) return res;
        return generateTrees(1,n);
    }
};
