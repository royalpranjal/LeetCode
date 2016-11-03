class Solution {
public:
    string sorted(string a){
        vector<int> sol;
        
        for(int i = 0; i < a.size(); i++){
            sol.push_back(a[i]);
        }
        
        sort(sol.begin(), sol.end());
        
        string s = "";
        
        for(int i = 0; i < sol.size(); i++){
            char c = sol[i];
            s = s + c;
        }
        
        return s;
        
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > sol;
        
        map<string, vector<string> > myMap;
        
        for(int i = 0; i < strs.size(); i++){
            string s = sorted(strs[i]);
            
            myMap[s].push_back(strs[i]);
        }
        
        map<string, vector<string> > :: iterator it = myMap.begin();
        
        while(it != myMap.end()){
            sol.push_back(it->second);
            it++;
        }
        
        return sol;
        
    }
};
