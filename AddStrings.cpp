class Solution {
public:
    void rev(string& s){
        int n = s.size();
        
        for(int i = 0; i < n/2; i++){
            char temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }
    }

    string addStrings(string num1, string num2) {
        string sol = "";
        
        int i = num1.size()-1, j = num2.size()-1;
        
        int carry = 0;
        
        while(i >=0 || j >= 0){
            int num = carry;
            
            if(i >= 0){
                num = num + num1[i] - '0';
                i--;
            }
            if(j >= 0){
                num = num + num2[j] - '0';
                j--;
            }
            carry = num/10;
            num = num%10;
            
            sol = sol + to_string(num);
        }
        
        if(carry){
            sol = sol + to_string(carry);
        }
        
        rev(sol);
        
        return sol;
    }
};
