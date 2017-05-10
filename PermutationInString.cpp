class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size(), i = 0, last = 0;
        
        if(!n){
            return true;
        }
        
        map<char, int> m1, m2;
        
        while(i < n){
            if(m1.find(s1[i]) == m1.end()){
                m1[s1[i]] = 1;
            }
            else{
                m1[s1[i]]++;
            }
            
            if(m2.find(s2[i]) == m2.end()){
                m2[s2[i]] = 1;    
            }
            else{
                m2[s2[i]]++;
            }
            
            i++;
        }
        
        while(i < m){
            if(m2 == m1){
                return true;
            }
                
            if(m2[s2[last]] == 1){
                m2.erase(m2.find(s2[last]));
            }
            else{
                m2[s2[last]]--;
            }
            last++;
            
            if(m2.find(s2[i]) == m2.end()){
                m2[s2[i]] = 1;    
            }
            else{
                m2[s2[i]]++;
            }
            
            i++;
        }
        
        if(m2 == m1){
            return true;
        }
        
        return false;
    }
};
