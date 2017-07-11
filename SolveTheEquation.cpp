#include <string>

class Solution {
public:
    int extract(string s, int& i){
        int n = s.size();
        
        string ans = "";
        
        bool neg = false;
        
        if(s[i] == '-'){
            neg = true;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        
        while(i < n && isdigit(s[i])){
            ans += s[i];
            i++;
        }
        
        int val = 1;
        
        if(ans.size() != 0){
            val = stoi(ans);
        }
        
        if(neg){
            val = -val;
        }
        
        return val;
    }
    
    string solveEquation(string equation) {
        int i = 0, n = equation.size(), lx = 0, lc = 0, rx = 0, rc = 0;
        
        string ans = "";
        
        while(i < n){
            int num = extract(equation, i);
            if(i < n && equation[i] == 'x'){
                lx += num;
                i++;
            }
            else{
                lc += num;
            }
            if(equation[i] == '='){
                i++;
                break;
            }
        }
        
        while(i < n){
            int num = extract(equation, i);
            if(i < n && equation[i] == 'x'){
                rx += num;
                i++;
            }
            else{
                rc += num;
            }
        }
        
        cout << "lx : " <<  lx << " lc : " << lc << " rx : " << rx << " rc : " << rc << endl;
        
        if((lc == rc) && (lx == rx)){
            ans = "Infinite solutions";
        }
        else if((lx-rx == 0) && (lc-rc != 0)){
            ans = "No solution";
        }
        else{
            ans = "x=";
            int val = (rc-lc)/(lx-rx);
            ans += to_string(val);
        }
            
        return ans;
    }
};
