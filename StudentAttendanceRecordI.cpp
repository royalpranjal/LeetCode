class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size(), i = 0, count = 0;
        
        while(i < n){
            if(s[i] == 'A'){
                count++;
            }
            if(s[i] == 'L'){
                if(i+2 < n){
                    if(s[i+1] == 'L' && s[i+2] == 'L'){
                        return false;
                    }
                }
            }
            
            if(count == 2){
                return false;
            }
            i++;
        }
        
        return true;
    }
};
