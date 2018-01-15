class Solution {
public:
    struct comp{
        bool operator()(string& s1, string& s2){
            int n = min(s1.size(), s2.size());
            for(int i = 0; i < n; i++){
                if(s1[i] > s2[i]){
                    return false;
                }
                else if(s1[i] < s2[i]){
                    return true;
                }
            }
            
            return s1.size() < s2.size();
        }
    };
    
    void merge(vector<string>& s1, vector<string>& s2){
        for(int i = 0; i < s2.size(); i++){
            s1.push_back(s2[i]);
        }
    }
    
    void makeAns(vector<string>& s, vector<vector<string> >& ans){
        vector<string> sol;
        
        set<string> temp_set;
        
        for(int i = 0; i < s.size(); i++){
            temp_set.insert(s[i]);
        }
        
        set<string> :: iterator it = temp_set.begin();
        
        
        while(it != temp_set.end()){
            sol.push_back(*it);    
            it++;
        }
        
        sort(sol.begin()+1, sol.end(), comp());
        ans.push_back(sol);
    }
    
    bool search(vector<string>& s, string key){
        for(int i = 1; i < s.size(); i++){
            if(s[i] == key){
                return true;
            }
        }
        
        return false;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                for(int j = 1; j < accounts[i].size(); j++){
                    for(int k = i+1; k < n; k++){
                        if(!visited[k]){
                            if(search(accounts[k], accounts[i][j])){
                                merge(accounts[i], accounts[k]);
                                visited[k] = true;
                            }
                        }
                    }
                }
            }
        }
        
        vector<vector<string> > ans;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                makeAns(accounts[i], ans);
            }
        }
        
        return ans;
    }
};
