/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.
// You may only use constant extra space.
// The given tree could be any binary tree.

//Wrong Answer
/*
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        TreeLinkNode* pre = root;
        TreeLinkNode* head = root;
        TreeLinkNode* tail;
        
        while(head != NULL) {
            if(pre->left != NULL) {
                if(pre->right != NULL) {
                    pre->left->next = pre->right;
                    tail = pre->right;
                } else tail = pre->left;
            } else {
                if(pre->right != NULL) tail = pre->right;
            }
            if(pre->next == NULL) {
                if(head->left != NULL) pre = head->left;
                else {
                    if(head->right != NULL) pre = head->right;
                    else {
                        if(pre->left != NULL) pre = pre->left;
                        else pre = pre->right;
                    }
                }
                head = pre;
                tail = NULL;
            } else {
                pre = pre->next;
                if(pre->left!= NULL) {
                    if(tail != NULL) tail->next = pre->left;
                } else {
                    if(pre->right != NULL) {
                        if(tail != NULL) tail->next = pre->right;
                    }
                }
            }
        }
        return;
    }
};
*/

//Answer
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        TreeLinkNode* head = NULL;
        TreeLinkNode* tail = NULL;
        TreeLinkNode* pre = root; //pre is on the previous level of head and tail
        
        while(pre != NULL) {
            if(pre->left != NULL) {
                if(head == NULL) { //start of a new level
                    head = pre->left;
                    tail = pre->left;
                } else { //link with previous nodes
                    tail->next = pre->left;
                    tail = tail->next;
                }
            }
            
            if(pre->right != NULL) {
                if(head == NULL) { //start of a new level
                    head = pre->right;
                    tail = pre->right;
                } else { //link with previous nodes
                    tail->next = pre->right;
                    tail = tail->next;
                }
            }
            
            pre = pre->next;
            
            if(pre == NULL) {
                pre = head;
                head = NULL; //*** mark the start of a new level
                tail = NULL; //***
            }
        }
        return;
    }
};
        
