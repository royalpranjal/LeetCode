class Solution {
public:
    string get(int n){
        if(n >= 2 && n <= 9){
            vector<string> v = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            return v[n-2];
        }
        return "";
    }
    
    void makeComb(string digits, int curr, string sol, vector<string>& ans){
        int n = digits.size();
        if(curr == n){
            ans.push_back(sol);
            return;
        }
        
        string dig = get(digits[curr]-'0');
        
        for(int i = 0; i < dig.size(); i++){
            makeComb(digits, curr+1, sol+dig[i], ans);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.size() == 0){
            return ans;
        }
        
        makeComb(digits, 0, "", ans);
        
        return ans;
    }
};
