class MapSum {
public:
    /** Initialize your data structure here. */
    struct Node{
        int val;
        vector<Node*> child;

        Node(int x=0){
            for(int i = 0; i < 26; i++){
                child.push_back(NULL);
            }
            val = x;
        }
    };
    
    Node* head;
    
    MapSum() {
        head = new Node();        
    }
    
    void insert(string key, int val) {
        Node* curr = head;
        
        for(int i = 0; i < key.size(); i++){
            if(curr->child[key[i]-'a'] == NULL){
                curr->child[key[i]-'a'] = new Node();
            }
            curr = curr->child[key[i]-'a'];
        }
        
        curr->val = val;
    }
    
    int getAns(Node* head){
        if(!head){
            return 0;
        }
        int ans = head->val;
        
        for(int i = 0; i < 26; i++){
            ans += getAns(head->child[i]);
        }
        
        return ans;
    }
    
    int sum(string prefix) {
        Node* curr = head;
        
        for(int i = 0; i < prefix.size(); i++){
            if(curr->child[prefix[i]-'a'] == NULL){
                return 0;
            }
            curr = curr->child[prefix[i]-'a'];
        }
        
        return getAns(curr);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
