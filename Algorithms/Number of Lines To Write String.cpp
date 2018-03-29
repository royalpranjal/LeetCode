class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int n = S.size(), line = 1, last = 0;
        
        if(!n){
            line = 0;
        }
        
        for(int i = 0; i < n; i++){
            int len = widths[S[i] - 'a'];
            if(last + len == 100){
                line++;
                last = 0;
            }
            else if(last + len > 100){
                line++;
                last = len;
            }
            else{
                last += len;
            }
        }
        
        vector<int> ans = {line, last};
        return ans;
    }
};
