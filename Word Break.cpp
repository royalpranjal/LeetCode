class Solution {
public:
    bool search(vector<string>& wordDict, string s){
        for(int i = 0; i < wordDict.size(); i++){
            if(wordDict[i] == s){
                return true;
            }
        }
        
        return false;
    }
    
    string sub(string s, int start, int end){
        string ans = "";
        
        for(int i = start; i < end; i++){
            ans += s[i];
        }
        
        return ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        vector<int> check(n+1, false);
        check[0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if(check[j-1]){
                    string substr = sub(s, j-1, i);
                    if(search(wordDict, substr)){
                        check[i] = true;
                        break;
                    }
                }
            }
        }
        
        return check[n];
    }
};
