class Solution {
public:
    void insertInMap(map<string, int>& dict, string s){
        if(dict.find(s) == dict.end()){
            dict[s] = 1;
        }
        else{
            dict[s]++;
        }
    }
    
    bool isSpecialChar(char c){
        return ispunct(c) || isspace(c);
    }
    
    string getWord(string& s, int& i, int len){
        string ans = "";
        
        while(i < len && !isSpecialChar(s[i])){
            if(s[i] <= 90){
                ans += (s[i] + 32);        
            }
            else{
                ans += s[i];        
            }
            
            i++;
        }
        
        return ans;
    }
    
    void forwardSepcialSymbol(string& paragraph, int& i, int strLen){
        while(i < strLen && isSpecialChar(paragraph[i])){
            i++;
        }
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> dict;
        
        int strLen = paragraph.size(), n = banned.size(), i = 0, maxi = 0;
        string ans = "";
        
        while(i < strLen){
            string word = getWord(paragraph, i, strLen);
            forwardSepcialSymbol(paragraph, i, strLen);
            insertInMap(dict, word);
        }
        
        for(int i = 0; i < n; i++){
            if(dict.find(banned[i]) != dict.end()){
                dict[banned[i]] = 0;
            }
        }
        
        map<string, int> :: iterator it = dict.begin();
        
        while(it != dict.end()){
            if(it->second > maxi){
                maxi = it->second;
                ans = it->first;
            }
            it++;
        }
        
        return ans;
    }
};
