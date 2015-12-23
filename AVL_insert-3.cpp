//4种rotation share functions
//add a dummy node before root

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

// From LC110
// Check if tree is balanced
int findDepth(TreeNode* root) {
    if(root == NULL) return 0;
    return 1 + max(findDepth(root->left),findDepth(root->right));
}

bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    int diffLR = findDepth(root->left)-findDepth(root->right);
    return (isBalanced(root->left) && isBalanced(root->right) && (diffLR <= 1) && (diffLR >= -1));
}

// Single rotation: L-L Rotation
void cwRotate(TreeNode* pre, TreeNode* node, TreeNode* move) {
    node->left = move->right;
    
    if(pre->left == node) {
        pre->left = move;
    } else {
        pre->right = move;
    }
    move->right = node;
    return;
}

// Single rotation: R-R Rotation
void ccwRotate(TreeNode* pre, TreeNode* node, TreeNode* move){
    node->right = move->left;
    
    if(pre->left == node) {
        pre->left = move;
    } else {
        pre->right = move;
    }
    move->left = node;
    return;
}

//Insert num to a balanced BST
void AVL_insert(TreeNode*& root, int num) {
    TreeNode* newNode = new TreeNode(num);
    if(root == NULL) {
        root = newNode;
        return;
    }
    
    TreeNode* dummyNode = new TreeNode(0);
    dummyNode->right = root;
    
    //Insertion
    stack<TreeNode*> stPath;
    stPath.push(dummyNode);
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
  
    //Balancing
    TreeNode* move;
    while(!stPath.empty()) {
        node = stPath.top();
        stPath.pop();
        if(node == dummyNode) break;
        
        node->leftHeight = findDepth(node->left);
        node->rightHeight = findDepth(node->right);
        if((node->leftHeight - node->rightHeight <= 1) && (node->leftHeight - node->rightHeight >= -1)) {
            move = node;
            continue;
        }
        TreeNode* pre = stPath.top();
        stPath.pop();
        if(node->leftHeight - node->rightHeight == 2) {
            if(move->leftHeight - move->rightHeight == 1) {
                //L-L Single Rotate: Clock-wise rotate
                cwRotate(pre, node, move);
            } else if(move->leftHeight - move->rightHeight == -1) {
                //L-R Double Rotate:CCW + CW
                //CCW
                TreeNode* moveRight = move->right;
                ccwRotate(node, move, moveRight);
                //CW
                cwRotate(pre, node, moveRight);
            }
            continue;
        } 
        if(node->leftHeight - node->rightHeight == -2) {
            if(move->leftHeight - move->rightHeight == -1) {
                //R-R Single Rotate: Counter-Clock-wise rotate
                ccwRotate(pre, node, move);
            } else if(move->leftHeight - move->rightHeight == 1){
                //R-L Double Rotate: CW + CCW
                //CW
                TreeNode* moveLeft = move->left;
                cwRotate(node, move, moveLeft);
                //CCW
                ccwRotate(pre, node, moveLeft);
            }
        }
    
    }
    
    root = dummyNode->right;
    return;
}

// To execute C++, please define "int main()"
int main() {
    vector<int> inputFix = {7, 1, 2, 3, 4, 5, 10, 6, 8, 9}; 
    
    // A random 1000 numbers input vector
    vector<int> input;
    for(int i=1; i<=1000; i++) {
        input.push_back(i);
    }
    for(int i=0; i<1000; i++) {
        srand(time(NULL));
        int swapInd = rand() % 1000;
        swap(input[i],input[swapInd]);
    }
    
    string s = "";
    TreeNode* root = deserialize(s);
    
    /*
    for(int i=0; i<10; i++) {
        AVL_insert(root, inputFix[i]);
        string res = serialize(root);
        cout<<res<<endl;
        cout<<isBalanced(root)<<endl;
        
    }
    */
    
    for(int i=0; i<1000; i++) {
        AVL_insert(root, input[i]);
    }
    string res = serialize(root);
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
