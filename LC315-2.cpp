//LC315
// You are given an integer array nums and you have to return a new counts array.
// The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
// Given nums = [5, 2, 6, 1]
// Return the array [2, 1, 1, 0].
// AVL_insert

// AVL balance BST
struct myTreeNode {
    int val;
    myTreeNode *left;
    myTreeNode *right;
    int count;
    int leftSize; //left subtree node counts
    int leftHeight;
    int rightHeight;
    myTreeNode(int x) : val(x), count(1), leftSize(0), leftHeight(0), rightHeight(0), left(NULL), right(NULL) {}
};

class Solution {
private:
    // Need to update leftSize, leftHeight and rightHeight info in rotations
    // Single rotation: L-L Rotation
    void cwRotate(myTreeNode* pre, myTreeNode* node, myTreeNode* move) {
        node->left = move->right;
        node->leftHeight = move->rightHeight;
        node->leftSize -= move->count + move->leftSize;
        
        if(pre->left == node) {
            pre->left = move;
            pre->leftHeight = 1 + max(move->leftHeight, move->rightHeight);
        } else {
            pre->right = move;
            pre->rightHeight = 1 + max(move->leftHeight, move->rightHeight);
        }
        move->right = node;
        move->rightHeight = 1 + max(node->leftHeight, node->rightHeight);
        
        return;
    }

    // Single rotation: R-R Rotation
    void ccwRotate(myTreeNode* pre, myTreeNode* node, myTreeNode* move){
        node->right = move->left;
        node->rightHeight = move->leftHeight;
        
        if(pre->left == node) {
            pre->left = move;
            pre->leftHeight = 1 + max(move->leftHeight, move->rightHeight);
        } else {
            pre->right = move;
            pre->rightHeight = 1 + max(move->leftHeight, move->rightHeight);
        }
        move->left = node;
        move->leftHeight = 1 + max(node->leftHeight, node->rightHeight);
        move->leftSize += node->leftSize + node->count;
        
        return;
    }

    //Insert num to a balanced BST
    void AVL_insert(myTreeNode*& root, int num, int& countSmaller) {
        myTreeNode* newNode = new myTreeNode(num);
        if(root == NULL) {
            root = newNode;
            return;
        }
        
        myTreeNode* dummyNode = new myTreeNode(0);
        dummyNode->right = root;
        
        //Insertion
        stack<myTreeNode*> stPath;
        stPath.push(dummyNode);
        myTreeNode* node = root;
        myTreeNode* pre = root;
      
        while(node != NULL) {
            if(node->val == num) {
                countSmaller += node->leftSize;
                node->count ++; //Orignal balanced BST unchanged
                return;
            }
            stPath.push(node);
            pre = node;
            if(node->val > num) {
                node->leftSize++;
                node = node->left;
            } else {
                countSmaller += node->leftSize + node->count;
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
        myTreeNode* move;
        while(!stPath.empty()) {
            node = stPath.top();
            stPath.pop();
            if(node == dummyNode) break;
            
            //node->leftHeight = findDepth(node->left);
            //node->rightHeight = findDepth(node->right);
            if(node->left != NULL) {
               node->leftHeight = 1 + max(node->left->leftHeight, node->left->rightHeight);
            }
            if(node->right != NULL) {
               node->rightHeight = 1 + max(node->right->leftHeight, node->right->rightHeight);
            }
            
            if((node->leftHeight - node->rightHeight <= 1) && (node->leftHeight - node->rightHeight >= -1)) {
                move = node;
                continue;
            }
            myTreeNode* pre = stPath.top();
            stPath.pop();
            if(node->leftHeight - node->rightHeight == 2) {
                if(move->leftHeight - move->rightHeight == 1) {
                    //L-L Single Rotate: Clock-wise rotate
                    cwRotate(pre, node, move);
                } else if(move->leftHeight - move->rightHeight == -1) {
                    //L-R Double Rotate:CCW + CW
                    //CCW
                    myTreeNode* moveRight = move->right;
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
                    myTreeNode* moveLeft = move->left;
                    cwRotate(node, move, moveLeft);
                    //CCW
                    ccwRotate(pre, node, moveLeft);
                }
            }
        
        }
        
        root = dummyNode->right;
        return;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty()) return {};
        
        int n = nums.size();
        vector<int> counts(n,0);
        if(n == 1) return counts;
        
        myTreeNode* root = new myTreeNode(nums[n-1]);

        for(int i = n-2; i >= 0; i--) {
            int countSmaller = 0;
            AVL_insert(root, nums[i], countSmaller);
            //addToTree(nums[i], root, countSmaller);
            counts[i] = countSmaller;
        }

        return counts;
    }
    
    void addToTree(int num, myTreeNode*& root, int& countSmaller) {
        myTreeNode* node = new myTreeNode(num);
        
        if(root == NULL) {
            root = node;
            return;
        }
        
        myTreeNode* cur = root;
        myTreeNode* pre = root;
        while(cur != NULL) {
            if(cur->val == num) {
                countSmaller += cur->leftSize;
                cur->count++;
                return;
            }

            if(cur->val > num) { //向左走
                cur->leftSize++;
                pre = cur;
                cur = cur->left;
            } else { //向右走
                countSmaller += cur->leftSize + cur->count;
                pre = cur;
                cur = cur->right;
            }
        }
        
        if(pre->val > num) {
            pre->left = node;
        } else {
            pre->right = node;
        }

        return;
    }
};
