// Donghee Lee
// 5/14/2020

class TrieNode {
public:
    bool key;
    vector<TrieNode*> nodes;
    TrieNode() {
        key = false;
        nodes = vector<TrieNode*>(26);
        for (int i = 0; i < 26; i++) {
            nodes[i] = nullptr;
        }
    }    
};

class Trie {
    
private: 
    TrieNode* root;
    
    TrieNode* find(string word, int & i) {
        return findr(word, i, root);
    }
    
    TrieNode* findr(string word, int & i, TrieNode* root) {
        if(word.length() == i || (root->nodes)[word[i] - 'a'] == nullptr) return root;
        int j = i;
        i++;
        return findr(word, i, (root->nodes)[word[i-1] - 'a']);
        
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int index = 0;
        TrieNode* tn = find(word, index);

        bool foundIt;
        if (tn == nullptr) {
            foundIt = false;
        } else {
            foundIt = tn->key;
        }

        
        if (!foundIt || index != word.length()) {
            
            for (int i = index; i < word.length(); i++) {
                if((tn->nodes)[word[i]-'a'] != nullptr) {
                    tn = (tn->nodes)[word[i]-'a'];
                } else {
                    // make new node
                    (tn->nodes)[word[i]-'a'] = new TrieNode();
                    tn = (tn->nodes)[word[i]-'a'];
                    if (i == word.length() - 1) {
                        tn->key = true;
                    }
                }
            }
            if (index == word.length()) {
                tn->key = true;
            }
           
        }

    }
    
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i = 0;
        TrieNode* tn = find(word, i);
        if (tn == nullptr) return false;
        if (i != word.length()) return false;
        return tn->key;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i = 0;
        find(prefix, i);
        return i == prefix.length();
    }
    
};
