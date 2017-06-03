class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int ans = m*n, r = m, c = n, len = ops.size();
        
        for(int i = 0; i < len; i++){
            int f = ops[i][0], s = ops[i][1];
            
            if(f*s > ans){
                if(f < r && s >= c){
                    ans = f*c;
                    r = f;
                }
                else if(f >= r && s < c){
                    ans = r*s;
                    c = s;
                }
            }
            else{
                if(r >= f && c >= s){
                    ans = f*s;
                    r = f;
                    c = s;
                }
                else if(r >= f && s >= c){
                    ans = f*c;
                    r = f;
                }
                else if(r < f && s <= c){
                    ans = r*s;
                    c = s;
                }
            }
        }
        
        return ans;
    }
};
