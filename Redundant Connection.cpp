class Solution {
public:
    struct Node{
        int x;
        Node* parent;
        Node(int val){
            this->x = val;
            parent = this;
        }
    };
    
    Node* getParent(Node* a){
        while(a->parent != a){
            a = a->parent;
        }
        
        return a;
    }
    
    void unionByRank(Node* &a, Node* &b){
        if(a->parent == a && b->parent == b){
            a->parent = b;
        }
        else if(a->parent == a){
            a->parent = getParent(b);
        }
        else if(b->parent == b){
            b->parent = getParent(a);
        }
        
        Node* b_parent = getParent(b);
        
        while(a->parent != a){
            Node* a_parent = getParent(a);
            a->parent = b_parent;
            a = a_parent;
        }
        
        a->parent = b_parent;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n =edges.size();
        
        vector<int> ans(2);
        
        map<int, Node*> m;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                if(m.find(edges[i][j]) == m.end()){
                    Node* node = new Node(edges[i][j]);    
                    m[edges[i][j]] = node;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(getParent(m[edges[i][0]]) != getParent(m[edges[i][1]])){
                unionByRank(m[edges[i][0]], m[edges[i][1]]);
            }
            else{
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
                break;
            }
        }
        
        return ans;
    }
};
