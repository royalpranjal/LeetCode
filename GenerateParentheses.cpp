class Solution {
public:
    void make(string s, int f, int b, vector<string>& ans){
        if(f == 0 && b == 0){
            ans.push_back(s);
            return;
        }
        if(f){
            make(s+"(", f-1, b, ans);
        }
        if(b && b > f){
            make(s+")", f, b-1, ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        make("", n, n, ans);
        
        return ans;
    }
};
