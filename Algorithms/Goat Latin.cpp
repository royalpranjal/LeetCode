class Solution {
public:
    bool isVowel(char c){
        vector<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        
        for(int i = 0; i < vowels.size(); i++){
            if(c == vowels[i]){
                return true;
            }
        }
        
        return false;
    }
    
    string getSubString(string s, int& curr, int& len){
        string ans = "";
        
        while(curr < len && !isspace(s[curr])){
            ans += s[curr];
            curr++;
        }
        
        return ans;
    }
    
    string getString(string s, int& curr, int len){
        char temp = ' ';
        bool vowel = true;
        
        if(!isVowel(s[curr])){
            temp = s[curr];
            vowel = false;
            curr++;
        }
        
        string ans = getSubString(s, curr, len);
        
        if(!vowel){
            ans += temp;
        }
        
        return ans;
    }
    
    string toGoatLatin(string S) {
        string ans = "", append = "maa";
        
        int n = S.size(), i = 0; 
        
        while(i < n){
            string temp = getString(S, i, n) + append;
            ans += temp;
            append += "a";
            i++;
            
            if(i < n){
                ans += " ";
            }
        }
        
        return ans;
    }
};
