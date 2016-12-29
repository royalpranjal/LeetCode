class Solution {
public:
    string getStr(string s, int start, int end){
        string ans = "";
        
        for(int i = start; i < end; i++){
            ans = ans + s[i];
        }
        
        return ans;
    }
    
    bool check(string pat, string temp){
        int n = pat.size(), m = temp.size();
        
        if(n%m != 0){
            return false;
        }
        
        for(int i = m; i < n; i = i + m){
            string t = getStr(pat, i, i+m);
            if(t != temp){
                return false;
            }
        }
        
        return true;
    }

    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        
        if(!n){
            return false;
        }
        
        string temp = "";
        
        for(int i = 0; i < n/2; i++){
            temp = temp + str[i];
            if(check(str, temp)){
                return true;
            }
        }    
        
        return false;
    }
};
