class Solution {
public:
    string rev(string s){
        int n = s.size();
        
        for(int i = 0; i < n/2; i++){
            char c = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = c;
        }
        
        return s;
    }    
    
    string add(string s1, string s2){
        s1 = rev(s1);
        s2 = rev(s2);
        
        string ans = "";
        
        int n1 = s1.size(), n2 = s2.size(), i = 0, carry = 0;
        
        while(i < n1 && i < n2){
            int sum = s1[i] - '0' + s2[i] - '0';
            ans = ans + to_string((sum+carry)%10);
            carry = (sum+carry)/10;
            i++;
        }
        
        while(i < n1){
            int sum = s1[i] - '0';
            ans = ans + to_string((sum+carry)%10);
            carry = (sum+carry)/10;
            i++;
        }
        
        while(i < n2){
            int sum = s2[i] - '0';
            ans = ans + to_string((sum+carry)%10);
            carry = (sum+carry)/10;
            i++;
        }
        
        if(carry){
            ans = ans + to_string(carry);
        }
        
        return rev(ans);
    }
    
    string mult(string s, char c, int a){
        s = rev(s);
        
        string ans = "";
        
        while(a){
            ans = ans + "0";
            a--;
        }
        
        int i = 0, n = s.size(), carry = 0;
        
        while(i < n){
            int sum = (s[i]-'0')*(c-'0');
            ans = ans + to_string((sum+carry)%10);
            carry = (sum+carry)/10;
            i++;    
        }
        
        if(carry){
            ans = ans + to_string(carry);
        }
        
        return rev(ans);
    }
    
    string multiply(string num1, string num2) {
        string ans = "";
        
        int n1 = num1.size(), n2 = num2.size();
        
        for(int i = n1-1; i >= 0; i--){
            ans = add(ans, mult(num2, num1[i], n1-i-1));
        }
        
        if(ans.size() == 0){
            return "0";
        }
        
        int count = 0;
        
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] != '0'){
                count++;
                break;
            }
        }
        
        if(!count){
            return "0";
        }
        
        return ans;
    }
};
