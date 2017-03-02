class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1 = s.size(), t1 = t.size();
        
        if(s1 != t1){
            return false;
        }
        
        map<char, int> m1, m2;
        
        for(int i = 0; i < s1; i++){
            if(m1.find(s[i]) == m1.end()){
                m1[s[i]] = 1;
            }
            else{
                m1[s[i]]++;
            }
        }
        
        for(int i = 0; i < t1; i++){
            if(m2.find(t[i]) == m2.end()){
                m2[t[i]] = 1;
            }
            else{
                m2[t[i]]++;
            }
        }
        
        if(m1 == m2){
            return true;
        }
        
        return false;
    }
};
