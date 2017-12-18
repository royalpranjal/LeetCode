class Solution {
public:
    char getNormalizedChar(char c){
        if(c >= 97 && c <= 122){
            return c;
        }
        
        return c + 32;
    }
    
    void makeMap(string licensePlate, map<char, int>& licenseMap){
        int n = licensePlate.size();
        
        for(int i = 0; i < n; i++){
            if(!isdigit(licensePlate[i]) && licensePlate[i] != ' '){
                char c = getNormalizedChar(licensePlate[i]);
                if(licenseMap.find(c) == licenseMap.end()){
                    licenseMap[c] = 1;
                }
                else{
                    licenseMap[c]++;
                }
            }
        }
    }
    
    bool mapHasAllZeroValues(map<char, int> m){
        map<char, int> :: iterator it = m.begin();
        
        while(it != m.end()){
            if(it->second > 0){
                return false;
            }
            
            it++;
        }
        
        return true;
    }
    
    bool check(string s, map<char, int> m){
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            char c = getNormalizedChar(s[i]);
            if(m.find(c) != m.end()){
                m[c]--;
            }
        }
        
        return mapHasAllZeroValues(m);
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char, int> licenseMap;
        
        makeMap(licensePlate, licenseMap);
        
        int minLength = INT_MAX, index = -1, n = words.size();
        
        for(int i = 0; i < n; i++){
            if(check(words[i], licenseMap)){
                if(minLength > words[i].size()){
                    minLength = words[i].size();
                    index = i;
                }
            }
        }
        
        return words[index];
    }
};
