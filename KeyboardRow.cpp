class Solution {
public:
    void makeM1(map<char, bool>& m){
        m['a'] = true;
        m['A'] = true;
        m['s'] = true;
        m['S'] = true;    
        m['d'] = true;
        m['D'] = true;
        m['f'] = true;
        m['F'] = true;
        m['g'] = true;
        m['G'] = true;
        m['h'] = true;
        m['H'] = true;
        m['j'] = true;
        m['J'] = true;
        m['k'] = true;
        m['K'] = true;
        m['l'] = true;
        m['L'] = true;
    }
    
    void makeM2(map<char, bool>& m){
        m['q'] = true;
        m['Q'] = true;
        m['w'] = true;
        m['W'] = true;    
        m['e'] = true;
        m['E'] = true;
        m['r'] = true;
        m['R'] = true;
        m['t'] = true;
        m['T'] = true;
        m['y'] = true;
        m['Y'] = true;
        m['u'] = true;
        m['U'] = true;
        m['i'] = true;
        m['I'] = true;
        m['o'] = true;
        m['O'] = true;
        m['p'] = true;
        m['P'] = true;
    }
    
    void makeM3(map<char, bool>& m){
        m['z'] = true;
        m['Z'] = true;
        m['x'] = true;
        m['X'] = true;    
        m['c'] = true;
        m['C'] = true;
        m['v'] = true;
        m['V'] = true;
        m['b'] = true;
        m['B'] = true;
        m['n'] = true;
        m['N'] = true;
        m['m'] = true;
        m['M'] = true;
    }
    
    bool belongsToOne(string s, map<char, bool> m1, map<char, bool> m2, map<char, bool> m3){
        if(s.size() == 0){
            return true;
        }
        
        if(m1.find(s[0]) != m1.end()){
            for(int i = 1; i < s.size(); i++){
                if(m1.find(s[i]) == m1.end()){
                    return false;
                }
            }
        }
        else if(m2.find(s[0]) != m2.end()){
            for(int i = 1; i < s.size(); i++){
                if(m2.find(s[i]) == m2.end()){
                    return false;
                }
            }
        }
        else if(m3.find(s[0]) != m3.end()){
            for(int i = 1; i < s.size(); i++){
                if(m3.find(s[i]) == m3.end()){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    vector<string> findWords(vector<string>& words) {
        vector<string> sol;
        
        map<char, bool> m1;
        map<char, bool> m2;
        map<char, bool> m3;
        
        makeM1(m1);
        makeM2(m2);
        makeM3(m3);
        
        for(int i = 0; i < words.size(); i++){
            if(belongsToOne(words[i], m1, m2, m3)){
                sol.push_back(words[i]);
            }
        }
        
        return sol;
    }
};
