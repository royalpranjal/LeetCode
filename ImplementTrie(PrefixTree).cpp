class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* next[26];
    bool leaf;
    
    TrieNode() {
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }
        leaf = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int n = word.size(), i = 0;
        
        TrieNode* curr = root;
        
        while(i < n){
            int a = word[i] - 97;
            if(curr->next[a] == NULL){
                TrieNode* temp = new TrieNode();
                curr->next[a] = temp;            
            }
            curr = curr->next[a];
            i++;
        }
        
        curr->leaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int i = 0, n = word.size();
        
        TrieNode* curr = root;
        
        while(i < n){
            int a = word[i] - 97;
            if(curr->next[a] == NULL){
                return false;
            }
            curr = curr->next[a];
            i++;
        }
        
        if(!curr->leaf){
            return false;
        }
        
        return i == n;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int i = 0, n = prefix.size();
        
        TrieNode* curr = root;
        
        while(i < n){
            int a = prefix[i] - 97;
            if(curr->next[a] == NULL){
                return false;
            }
            curr = curr->next[a];
            i++;
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
