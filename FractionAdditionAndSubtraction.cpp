class Solution {
public:
    string get(string s, int& i){
        string ans = "";
        
        if(s[i] == '-' || s[i] == '+'){
            ans = s[i];
            i++;
        }
        
        while(!(s[i] == '+' || s[i] == '-') && i < s.size()){
            ans = ans + s[i];
            i++;
        }
        
        return ans;
    }
    
    void getValues(string s, int& num, int& den){
        string numi = "", deni = "";
        
        int i = 0;
        
        if(s[i] == '-'){
            numi = "-";
            i++;
        }
        
        while(s[i] != '/'){
            numi = numi + s[i];
            i++;
        }
        
        i++;
        
        num = stoi(numi);
        
        while(i < s.size()){
            deni = deni + s[i];
            i++;
        }
        
        den = stoi(deni);
        
        // cout << "stoi(num) " << num << "...stoi(den)" << den << endl;
    }
    
    void simplify(int& v, int& d){
        if(v == 0){
            d = 1;
            return;
        }
        else if(v == d){
            v = 1;
            d = 1;
            return;
        }
        
        int i = 2;
        
        while(i < max(v, d)){
            if(v%i == 0 && d%i == 0){
                v = v/i;
                d = d/i;
            }
            else{
                i++;
            }
        }
    }
    
    void solve(string& s1, string s2){
        if(s1.size() == 0){
            s1 = s2;
            return;
        }
        
        int n1, n2, d1, d2;
        
        getValues(s1, n1, d1);
        getValues(s2, n2, d2);
        
        int d = d1*d2, v = n1*d2 + n2*d1;
        
        simplify(v, d);
        
        s1 = to_string(v) + "/" + to_string(d);
    }

    string fractionAddition(string expression) {
        string ans = "";
        
        int i = 0, n = expression.size();
        
        while(i < n){
            string temp = get(expression, i);
            solve(ans, temp);
            // cout << "ans " << ans << "...temp " << temp << endl;
        }
        
        return ans;
    }
};
