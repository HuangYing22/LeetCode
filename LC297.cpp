//**LC297
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
// Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string numToString(int num) {
        string res = "";
        if(num < 10) {
            res.push_back('0' + num); //当num < 0时, 转换成一个不是数的char, 但是通过stringToNum可以正确地转换回来
            return res;
        }
        
        res = numToString(num/10);
        res.append(numToString(num%10));
        return res;
    }
    
    int stringToNum(string s) {
        int l = s.length();
        int res = 0;
        for(int i = 0; i < l; i ++) {
            res *= 10;
            res += s[i] - '0';
        }
        return res;
    }
    
    /*
    int findDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if((root->left == NULL) && (root->right == NULL)) return 1;
        return 1 + max(findDepth(root->left), findDepth(root->right));
    }
    */
    
public:

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
                res.append("NULL ");
                continue;
            }
            //string buffer = numToString(node->val);
            //res.append(buffer);
            res.append(to_string(node->val));
            res.append(" ");
            q.push(node->left);
            q.push(node->right);
        }
        
        return res;
    }
    
    //**正解
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        
        TreeNode* root;
        TreeNode* node;
        queue<TreeNode*> q;
        int l = data.length();
        int i = 0;
        int j = 0;
        
        /*
        while((data[i + j] != ' ') && ((i + j) < l)) {
            j ++;
        }
        string cur = data.substr(i, j);
        */
        
        j = data.find(' ', i); //find the first index of ' ' after index i
        string cur = data.substr(i, j - i);
        
        if(cur != "NULL") {
            //int num = stringToNum(cur);
            int num = stoi(cur);
            root = new TreeNode(num);
            q.push(root);
        }
        
        //i = i + j + 1;
        i = j + 1;
        
        bool tag = true; //tag true/false 添左边右边各一次
        
        while(i < l) {
            if(tag) { //每两次从q里取一次
                node = q.front();
                q.pop();
            }
            tag = !tag;
            
            /*
            int j = 0;
            while((data[i + j] != ' ') && ((i + j) < l)) {
                j ++;
            }
            string cur = data.substr(i, j);
            */
            
            j = data.find(' ', i); //find the first index of ' ' after index i
            if(j >= l) break;
            cur = data.substr(i, j - i);
            
            if(cur != "NULL") {
                //int num = stringToNum(cur);
                int num = stoi(cur);
                if(!tag) {
                    node->left = new TreeNode(num);
                    q.push(node->left);
                } else {
                    node->right = new TreeNode(num);
                    q.push(node->right);
                }
            }
            //i = i + j + 1;
            i = j + 1;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
