class WordDictionary {
public:
    struct Node{
        Node* next[26];
        bool leaf;
        
        Node(){
            for(int i = 0; i < 26; i++){
                next[i] = NULL;
            }
            leaf = false;
        }
    };
    
    Node* head;
    
    WordDictionary(){
        head = new Node();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        int i = 0, n = word.size();
        
        Node* curr = head;
        
        while(i < n){
            int a = word[i] - 97;
            if(curr->next[a] == NULL){
                Node* temp = new Node();
                curr->next[a] = temp;
            }
            curr = curr->next[a];
            i++;
        }
        
        curr->leaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(Node* curr, int i, int n, string s){
        if(curr == NULL){
            return false;
        }
        if(i == n){
            if(curr->leaf == true){
                return true;
            }
            return false;
        }
        if(s[i] == '.'){
            bool ans = false;
            for(int j = 0; j < 26; j++){
                if(curr->next[j] != NULL){
                    ans = ans || search(curr->next[j], i+1, n, s);
                }
            }
            return ans;
        }
        else{
            int a = s[i] - 97;
            if(curr->next[a] == NULL){
                return false;
            }
            return search(curr->next[a], i+1, n, s);
        }
        return true;
    }
    
    bool search(string word) {
        int i = 0, n = word.size(); 
        
        Node* curr = head;
        
        return search(curr, i, n, word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
