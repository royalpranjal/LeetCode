class Solution {
public:
    int rank(char c){
        if(c == 'M'){
            return 1000;
        }
        else if(c == 'D'){
            return 500;
        }
        else if(c == 'C'){
            return 100;
        }
        else if(c == 'L'){
            return 50;
        }
        else if(c == 'X'){
            return 10;
        }
        else if(c == 'V'){
            return 5;
        }
        return 1;
    }
    
    int romanToInt(string s) {
        int ans = 0, n = s.size(), i = 0;
        
        while(i < n){
            if(i+1 < n){
                if(rank(s[i]) >= rank(s[i+1])){
                    ans = ans + rank(s[i]);
                    i++;
                }
                else{
                    ans = ans + rank(s[i+1]) - rank(s[i]);
                    i += 2;
                }
            }
            else{
                ans = ans + rank(s[i]);
                i++;
            }
        }
        
        return ans;
    }
};
