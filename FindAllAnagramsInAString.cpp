class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> forP;
        
        for(int i = 0; i < p.size(); i++){
            if(forP.find(p[i]) == forP.end()){
                forP[p[i]] = 1;
            }
            else{
                forP[p[i]]++;    
            }
        }
        
        int start = 0, i = 0, n = s.size();
        
        map<char, int> m;
        
        vector<int> sol;
        
        while(i < n){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = 1;
            }
            else{
                m[s[i]]++;
            }
            
            if((i - start) == p.size()){
                if(m[s[start]] == 1){
                    m.erase(m.find(s[start]));
                }
                else{
                    m[s[start]]--;
                }
                start++;
            }
            
            if(m == forP){
                sol.push_back(start);
                
            }
            i++;
        }
        
        return sol;
    }
};
