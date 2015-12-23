//4种rotation没有share function
//没有dummyNode
#include <iostream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    int count;
    int leftHeight;
    int rightHeight;
    TreeNode(int x) : val(x), left(NULL), right(NULL), count(1), leftHeight(0), rightHeight(0) {}
};

// From LC297 Serialize and Deserialize Binary Tree
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == NULL) return "";

    string res = "";
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* node;

    while(!q.empty()) {
        node = q.front();
        q.pop();
        if(node == NULL) {
            res.append("# ");
            continue;
        }
        res.append(to_string(node->val));
        res.append(" ");
        q.push(node->left);
        q.push(node->right);
    }

    return res;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data == "") return NULL;

    TreeNode* root;
    TreeNode* node;
    queue<TreeNode*> q;
    int l = data.length();
    int i = 0;
    int j = 0;

    j = data.find(' ', i); //find the first index of ' ' after index i
    string cur = data.substr(i, j - i);
        
    if(cur != "#") {
        int num = stoi(cur);
        root = new TreeNode(num);
        q.push(root);
    }

    i = j + 1;

    bool tag = true; //tag true/false 添左边右边各一次

    while(i < l) {
        if(tag) { //每两次从q里取一次
            node = q.front();
            q.pop();
        }
        tag = !tag;

        j = data.find(' ', i); //find the first index of ' ' after index i
        if(j >= l) break;
        cur = data.substr(i, j - i);

        if(cur != "#") {
            int num = stoi(cur);
            if(!tag) {
                node->left = new TreeNode(num);
                q.push(node->left);
            } else {
                node->right = new TreeNode(num);
                q.push(node->right);
            }
        }

        i = j + 1;
    }

    return root;
}


int maxHeight(TreeNode* root) {
    if(root == NULL) return 0;
    return 1 + max(maxHeight(root->left), maxHeight(root->right));
}

void cwRotate(TreeNode*& root, TreeNode* node, TreeNode* move, stack<TreeNode*>& stPath) {
    if(stPath.empty()) {
        node->left = move->right;
        move->right = node;
        root = move;
        return;
    }
    
    pre = stPath.top();
    stPath.pop();
    node->left = move->right;
    
    if(pre->left == node) {
        pre->left = move;
    } else if(pre->right == node) {
        pre->right = move;
    }
    move->right = node;
    return;
}

void ccwRotate(TreeNode*& root, TreeNode* node, TreeNode* move, stack<TreeNode*>& stPath){
    if(stPath.empty()) {
        node->right = move->left;
        move->left = node;
        root = move;
        return;
    }
    pre = stPath.top();
    stPath.pop();
    node->right = move->left;
    if(pre->left == node) {
        pre->left = move;
    } else if(pre->right == node) {
        pre->right = move;
    }
    move->left = node;
    return;
}
void AVL_insert(TreeNode*& root, int num) {
    TreeNode* newNode = new TreeNode(num);
    if(root == NULL) {
        root = newNode;
        return;
    }

    //insert
    stack<TreeNode*> stPath;
    TreeNode* node = root;
    TreeNode* pre = root;
  
    while(node != NULL) {
        if(node->val == num) {
            node->count ++; //Orignal balanced BST unchanged
            return;
        }
        stPath.push(node);
        pre = node;
        if(node->val > num) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
  
    if(pre->val > num) {
        pre->left = newNode;
    } else {
        pre->right = newNode;
    }
    stPath.push(newNode);
  
    //re-balance
    TreeNode* move;
    while(!stPath.empty()) {
        node = stPath.top();
        stPath.pop();
        node->leftHeight = maxHeight(node->left);
        node->rightHeight = maxHeight(node->right);
        if((node->leftHeight - node->rightHeight <= 1) && (node->leftHeight - node->rightHeight >= -1)) {
            move = node;
            continue;
        }
        if(node->leftHeight - node->rightHeight == 2) {
            if(move->leftHeight - move->rightHeight == 1) {
                //L-L Single Rotate: Clock-wise rotate
                if(stPath.empty()) {
                    node->left = move->right;
                    move->right = node;
                    root = move;
                    return;
                }
                pre = stPath.top();
                stPath.pop();
                node->left = move->right;
                if(pre->left == node) {
                    pre->left = move;
                } else if(pre->right == node) {
                    pre->right = move;
                }
                move->right = node;
                continue;
            } else if(move->leftHeight - move->rightHeight == -1) {
                //L-R Double Rotate:CCW + CW
                //CCW
                TreeNode* moveRight = move->right;
                move->right = moveRight->left;
                node->left = moveRight;
                moveRight->left = move;
                //CW
                if(stPath.empty()) {
                    node->left = moveRight->right;
                    moveRight->right = node;
                    root = moveRight;
                    return;
                }
                pre = stPath.top();
                stPath.pop();
                node->left = moveRight->right;
                if(pre->left == node) {
                    pre->left = moveRight;
                } else if(pre->right == node) {
                    pre->right = moveRight;
                }
                moveRight->right = node;
                continue;
            }
        } 
        if(node->leftHeight - node->rightHeight == -2) {
            if(move->leftHeight - move->rightHeight == -1) {
                //R-R Single Rotate: Counter-Clock-wise rotate
                if(stPath.empty()) {
                    node->right = move->left;
                    move->left = node;
                    root = move;
                return;
                }
                pre = stPath.top();
                stPath.pop();
                node->right = move->left;
                if(pre->left == node) {
                    pre->left = move;
                } else if(pre->right == node) {
                    pre->right = move;
                }
                move->left = node;
            } else if(move->leftHeight - move->rightHeight == 1){
                //R-L Double Rotate: CW + CCW
                //CW
                TreeNode* moveLeft = move->left;
                move->left = moveLeft->right;
                node->right = moveLeft;
                moveLeft->right = move;
                //CCW
                if(stPath.empty()) {
                    node->right = moveLeft->left;
                    moveLeft->left = node;
                    root = moveLeft;
                    return;
                }
                pre = stPath.top();
                stPath.pop();
                node->right = moveLeft->left;
                if(pre->left == node) {
                    pre->left = moveLeft;
                } else if(pre->right == node) {
                    pre->right = moveLeft;
                }
                moveLeft->left = node;
                continue;
            }
        }
    
    }
    return;
}

//Check if tree is balanced
int findDepth(TreeNode* root) {
    if(root == NULL) return 0;
    return 1+max(findDepth(root->left),findDepth(root->right));
}

bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    int diffLR = findDepth(root->left)-findDepth(root->right);
    return (isBalanced(root->left) && isBalanced(root->right) && (diffLR <= 1) && (diffLR >= -1));
}


// To execute C++, please define "int main()"
int main() {
    //string s = "5 2 6 1 3 # # # # # # ";
    //string s = "10 2 15 # # 13 17 # # # # # # ";
    vector<int> input;
    for(int i=1; i<=1000; i++) {
        input.push_back(i);
    }
    for(int i=0; i<1000; i++) {
        srand(time(NULL));
        int swapInd = rand() % 1000;
        swap(input[i],input[swapInd]);
    }

    string s = "0 # # ";
    TreeNode* root = deserialize(s);
    //vector<int> inputFix = {7, 1, 2, 3, 4, 5, 10, 6, 8, 9}; 
    for(int i=0; i<1000; i++) {
        //AVL_insert(root, inputFix[i]);
        AVL_insert(root, input[i]);
        
    }
    string res = serialize(root);
    //cout<<res<<endl;
    cout<<isBalanced(root)<<endl;
    return 0;
}


/* 
Your previous Plain Text content is preserved below:

This is just a simple shared plaintext pad, with no execution capabilities.

When you know what language you'd like to use for your interview,
simply choose it from the dropdown in the top bar.

You can also change the default language your pads are created with
in your account settings: https://coderpad.io/profile

Enjoy your interview!


 */
