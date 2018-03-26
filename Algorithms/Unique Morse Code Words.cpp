class Solution {
public:
    string getMorseCode(char c){
        vector<string> morseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        return morseCode[c - 'a'];
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> uniqueCodes;
        
        int n = words.size();
        
        for(int i = 0; i < n; i++){
            int len = words[i].size();
            string code = "";
            
            for(int j = 0; j < len; j++){
                code += getMorseCode(words[i][j]);
            }
            
            uniqueCodes.insert(code);
        }
        
        return uniqueCodes.size();
    }
};
