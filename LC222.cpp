//** LC222
//Time Limit Exceeded O(n)
/*
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
*/

//Time Limit Exceeded
/*
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        int res = 1;
        int depth = 0;
        
        TreeNode* ptr = root;
        while(ptr->left != NULL) {
            res += depth*2;
            depth ++;
            ptr = ptr->left;
        }
        
        stack<TreeNode *> st;
        st.push(root);
        
        TreeNode* nd;
        while(!st.empty()) {
            nd = st.top();
            st.pop();
            
            if((nd->left != NULL) && (nd->right != NULL)) {
                st.push(nd->right);
                st.push(nd->left);
            }
            if((nd->left == NULL) && (nd->right == NULL)) {
                res ++;
            }
            if((nd->left != NULL) && (nd->right == NULL)) {
                res ++;
                break;
            }
        }
        
        return res;
    }
        
};
*/

//正解
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        if((root->left == NULL) && (root->right == NULL)) return 1;
        int l = countLeftDepth(root);
        int r = countRightDepth(root);
        if(l == r) return (1<<l)-1; //<<表示2的乘方
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
    
    int countLeftDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        while (root != NULL) {
            res ++;
            root = root->left;
        }
        return res;
    }
    
    int countRightDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        while (root != NULL) {
            res ++;
            root = root->right;
        }
        return res;
    }
        
};
