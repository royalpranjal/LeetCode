class Solution {
public:
    void getReal(string s, int& start, int end, int& ans){
        string temp = "";
        
        while(s[start] != '+'){
            temp = temp + s[start];
            start++;
        }
        start++;
        
        ans = stoi(temp);
    }
    
    void getCom(string s, int start, int end, int& ans){
        string temp = "";
        
        while(start < end){
            temp = temp + s[start];
            start++;
        }
        
        ans = stoi(temp);
    }
    
    string complexNumberMultiply(string a, string b) {
        int realA, realB, comA, comB, n = a.size(), m = b.size(), startA = 0, startB = 0;
        
        if(a[0] == '-'){
            startA++;
            getReal(a, startA, n, realA);
            realA = -realA;
        }
        else{
            getReal(a, startA, n, realA);
        }
        
        if(b[0] == '-'){
            startB++;
            getReal(b, startB, m, realB);
            realB = -realB;
        }
        else{
            getReal(b, startB, m, realB);
        }
        
        if(a[startA] == '-'){
            startA++;
            getCom(a, startA, n, comA);
            comA = -comA;
        }
        else{
            getCom(a, startA, n, comA);
        }
        
        if(b[startB] == '-'){
            startB++;
            getCom(b, startB, m, comB);
            comB = -comB;
        }
        else{
            getCom(b, startB, m, comB);
        }
        
        string ans = "";
        
        int real = (realA*realB) - (comA*comB), complex = (realA*comB) + (realB*comA);
        
        ans = ans + to_string(real) + "+" + to_string(complex) + "i";
        
        return ans;
    }
};
