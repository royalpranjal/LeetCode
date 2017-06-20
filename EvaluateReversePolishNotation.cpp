class Solution {
public:
    string check(int a, int b, string c){
        int ans;
        if(c == "+"){
            ans = a + b;
        }
        else if(c == "-"){
            ans = b - a;
        }
        else if(c == "*"){
            ans = b * a;
        }
        else{
            ans = (b/a);    
        }
        
        return to_string(ans); 
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        
        for(int i = 0; i < tokens.size(); i++){
            if((tokens[i] == "+") || (tokens[i] == "-") || (tokens[i] == "/") || (tokens[i] == "*")){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                st.push(check(a, b, tokens[i]));
            }
            else{
                st.push(tokens[i]);
            }
        }
        
        return stoi(st.top());
    }
};
