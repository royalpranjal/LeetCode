class Solution {
public:
    int countSegments(string s) {
        int ans = 0, n = s.size(), i = 0;
        
        bool going = false;
        
        while(i < n){
            if(isspace(s[i])){
                if(going){
                    ans++;
                    going = false;
                }
            }
            else{
                going = true;
            }
            
            i++;
        }
        
        if(going){
            ans++;
        }
        
        return ans;
    }
};
