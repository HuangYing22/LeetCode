//LC208
//Implement a trie with insert, search, and startsWith methods.
//You may assume that all inputs are consist of lowercase letters a-z.

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isEnd = false;
        child = vector<TrieNode*>(26,NULL); //reserve了26个NULL
    }
    
    bool isEnd;
    //TrieNode* child[26]; //runtime error
    //不initialize的话这26个元素不是NULL,爱是啥是啥
    vector<TrieNode*> child;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(word == "") return;
        
        unsigned int n = word.length();
        TrieNode* cur = root;
        
        for(unsigned int i=0; i<n; i++) {
            int index = word[i]-'a';
            if(cur->child[index] == NULL) {
                cur->child[index] = new TrieNode();
            }
            cur = cur->child[index];
        }
        cur->isEnd = true;
        return;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if(word == "") {
            return root->isEnd;
        }
        
        unsigned int n = word.length();
        TrieNode* cur = root;
        
        for(unsigned int i=0; i<n; i++) {
            int index = word[i]-'a';
            if(cur->child[index] == NULL) return false;
            cur = cur->child[index];
        }
        
        return cur->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        unsigned int n = prefix.length();
        TrieNode* cur = root;
        
        for(unsigned int i=0; i<n; i++) {
            int index = prefix[i]-'a';
            if(cur->child[index] == NULL) return false;
            cur = cur->child[index];
        }
        
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
