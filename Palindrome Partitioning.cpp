class Solution {
public:
    bool stringIsPalindrome(string s){
        int n = s.size();
        
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n-i-1]){
                return false;
            }
        }
        
        return true;
    }
    
    bool checkPalindrome(vector<string> temp){
        for(int i = 0; i < temp.size(); i++){
            if(!stringIsPalindrome(temp[i])){
                return false;
            }
        }
        
        return true;
    }
    
    void check(string& s, int curr, string currS, vector<string> temp, vector<vector<string> >& ans){
        int n = s.size();
        
        if(curr == n){
            temp.push_back(currS);
            if(checkPalindrome(temp)){
                ans.push_back(temp);
            }
            return;
        }
        
        check(s, curr+1, currS + s[curr], temp, ans);    
        
        if(currS.size() && stringIsPalindrome(currS)){
            vector<string> temp1(temp);
            temp1.push_back(currS);
            string t = "";
            t += s[curr];
            check(s, curr+1, t, temp1, ans);    
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> temp;
        
        check(s, 0, "", temp, ans);
        
        return ans;
    }
};
